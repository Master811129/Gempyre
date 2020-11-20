#include <gempyre.h>
#include <gempyre_utils.h>
#include <gempyre_client.h>
#include "affiliates_test_resource.h"
#include <iostream>

int main(int argc, char* argv[]) {
    const auto plist = GempyreUtils::parseArgs(argc, argv, {});
    gempyre_utils_assert_x(!std::get<GempyreUtils::ParamList>(std::get<GempyreUtils::Params>(plist)).empty(), "expected path to affiliates");
    const std::string py = std::get<GempyreUtils::ParamList>(std::get<GempyreUtils::Params>(plist))[0];

    Gempyre::Ui ui({{"/affiliates_test.html", Affiliates_testhtml}},
                 "affiliates_test.html", py, "500 640 \"Test Affiliates\"");

    Gempyre::Element content(ui, "content");
    Gempyre::Element openFile(ui, "open_file");
    Gempyre::Element openFiles(ui, "open_files");
    Gempyre::Element openDir(ui, "open_dir");
    Gempyre::Element saveFile(ui, "saveFile");

    openFile.subscribe("click", [&ui, &content](const Gempyre::Event&) {
        const auto out = GempyreClient::Dialog<Gempyre::Ui>(ui).openFileDialog("", "", {{"Text", {"*.txt"}}});
        if(out) {
            std::string stuff;
            std::ifstream f;
            f.open (*out);
            f >> stuff;
            f.close();
            content.setHTML(stuff + "</br>" + "size:" + std::to_string(GempyreUtils::fileSize(*out)));
        }
    });

    openFiles.subscribe("click", [&ui, &content](const Gempyre::Event&) {
        const auto out = GempyreClient::Dialog<Gempyre::Ui>(ui).openFilesDialog();
        if(out) {
            std::string line;
            for(const auto& o : *out) {
                line += "filename:" + o + " size:" + std::to_string(GempyreUtils::fileSize(o)) + "</br>";
            }
            content.setHTML(line);
        }
    });

    openDir.subscribe("click", [&ui, &content](const Gempyre::Event&) {
        const auto out = GempyreClient::Dialog<Gempyre::Ui>(ui).openDirDialog("dir");
        if(out) {
            const auto dirlist = GempyreUtils::directory(*out);
            std::string line;
            for(const auto& d : dirlist) {
                line += std::get<0>(d) +"</br>";
            }
            content.setHTML(line);
        }
    });

    saveFile.subscribe("click", [&ui, &content](const Gempyre::Event&) {
        const auto out = GempyreClient::Dialog<Gempyre::Ui>(ui).saveFileDialog("", "", {{"Text", {"*.txt, *.text"}}, {"Log", {"*.log"}}});
        if(out) {
            if(GempyreUtils::fileExists(*out)) {
                 content.setHTML("Do not pick existing file:" + *out);
                 return;
            }
            std::string stuff;
            std::ofstream f;
            f.open (*out);
            f << *content.html();
            f.close();
            content.setHTML("Written in file, size:" + std::to_string(GempyreUtils::fileSize(*out)));
        }
    });


    ui.run();
    return 0;
}

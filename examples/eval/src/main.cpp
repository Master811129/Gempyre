#include "gempyre.h"
#include "eval_resource.h"

int main(int /*argc*/, char** /*argv*/) {
    Gempyre::setDebug(true);
    Gempyre::Ui ui(Eval_resourceh, "eval.html");
    ui.eval(R"(var para = document.createElement("P");
            var t = document.createTextNode("This is a paragraph.");
            para.appendChild(t);
            document.getElementById("myDIV").appendChild(para);)");
    ui.run();
}

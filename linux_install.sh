set -e 

PREFIX=$1

if [[ $PREFIX -ne "" && ! -d $PREFIX ]]; then
    echo "$PREFIX not found"
    return 
fi

mkdir -p build

pushd build

cmake ..  -DCMAKE_BUILD_TYPE=Debug -DHAS_AFFILIATES=ON -DHAS_TEST=OFF -DHAS_EXAMPLES=ON -DUSE_PYTHON_UI=ON
cmake --build . --config Debug
sudo cmake --install . --config Debug

cmake ..  -DCMAKE_BUILD_TYPE=Release -DHAS_AFFILIATES=ON -DHAS_TEST=OFF -DHAS_EXAMPLES=ON -DUSE_PYTHON_UI=ON
cmake --build . --config Release
sudo cmake --install . --config Release

popd

if [[ "$ACTIONS" != "TRUE" ]]; then
    echo "Run install test"
    pip3 install pywebview
    bash ./test/install_test/install_test.sh build
fi

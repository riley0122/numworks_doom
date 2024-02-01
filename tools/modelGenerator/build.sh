cmake -B build -S .

cd build
make
mkdir -p ../dist
mv ./src/modelGenerator ../dist/modelGenerator
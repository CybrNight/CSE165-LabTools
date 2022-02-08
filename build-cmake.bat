set dest=build

mkdir %dest%
cd %dest%
cmake ..
cmake --build . --config Release
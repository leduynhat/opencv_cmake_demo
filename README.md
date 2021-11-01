## OpenCV using cmake demo on ubuntu

1. Install opencv into your system follow this instuction
```sh
https://linuxize.com/post/how-to-install-opencv-on-ubuntu-20-04/
```
2. Export path 
```sh
sudo gedit ~/.bashrc
```
add this line at the end of that file
```sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/
```
3. From root folder of this project, create /build folder and change dir into
```sh
mkdir build && cd build
```
4. build this project  
```sh
cmake ..
```
5. make file
```sh
make
```
6. run 
```sh
./bin/helloOpenCV
```

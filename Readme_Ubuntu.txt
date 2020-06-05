On your Ubuntu workstation (Desktop/Laptop):

0. Install Codeblocks (ignore if already installed)
sudo apt-get update
sudo apt-get install codeblocks

Install OpenGL
sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

1. Download and extract "OpenGL_Ubuntu.zip". A directory "OpenGL_Ubuntu" will be generated
2. Inside OpenGL_Ubuntu directory, you will find a file "OpenGL_Ubuntu.cbp" 
3. Launch Codeblocks
4. Drag and drop OpenGL_Ubuntu.cbp on Codeblocks editor
5. Click on "Build and Run"
6. Make changes inside "draw" function in main.cpp
7. Change the arguments to "gluLookAt" inside "display" function. Try to understand how it affects the generated image
8. if that does not work do: g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL

Reference: http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/

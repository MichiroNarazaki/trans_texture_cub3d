# How To Use

1. git clone https://github.com/lowzzy/trans_texture_cub3d
2. git clone https://github.com/lowzzy/mms_and_opengl
3. vim trans_texture_cub3d/Makefile
4. fix path and esc -> :q to save
5. vim trans_texture_cub3d/srcs/main.c 
6. fix path and esc -> :q to save
7. cd mms_and_opengl/opengl
8. make
9. cd ../mms
10. make
11. mv libmlx.dylib ../../trans_texture_cub3d/
12. cd ../../trans_texture_cub3d/
13. make
14. ./translate.a

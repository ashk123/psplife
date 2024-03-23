cmake_minimum_required(VERSION 3.5)

project(GameOfLife)

add_executable(${PROJECT_NAME} src/main.c src/rect.c src/callback.c src/life.c src/ctrl.c)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pspgu
    pspge
    pspdisplay
	pspctrl
)

# Create an EBOOT.PBP file
create_pbp_file(
    TARGET ${PROJECT_NAME}
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE ${PROJECT_NAME}
    VERSION 01.00
)



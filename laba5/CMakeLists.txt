cmake_minimum_required(VERSION 3.15)
project(AssemblyLabs LANGUAGES C ASM_NASM)

# Настройка для NASM под Windows (x64)
if(WIN32)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)
    set(CMAKE_ASM_NASM_FLAGS "-f win64")
endif()

# Поиск всех папок с заданиями
file(GLOB SUB_DIRECTORIES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*")

foreach(DIR ${SUB_DIRECTORIES})
    # Игнорируем папку сборки
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}" AND NOT "${DIR}" STREQUAL "build")
        
        file(GLOB C_FILES "${DIR}/*.c" "${DIR}/*.cpp")
        file(GLOB ASM_FILES "${DIR}/*.asm")
        
        if(ASM_FILES)
            set(TARGET_NAME "${DIR}")
            message(STATUS "Найдено задание: ${TARGET_NAME}")
            
            # Создаем исполняемый файл
            add_executable(${TARGET_NAME} ${C_FILES} ${ASM_FILES})
            
            # Если проект состоит ТОЛЬКО из ASM, нужно явно подключить библиотеку C
            # для работы таких функций как printf
            if(NOT C_FILES)
                if(MINGW)
                    # Для MinGW линкуем системные библиотеки напрямую
                    target_link_libraries(${TARGET_NAME} PRIVATE msvcrt)
                endif()
            endif()
        endif()
    endif()
endforeach()
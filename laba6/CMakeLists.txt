cmake_minimum_required(VERSION 3.15)
project(AssemblyLabs LANGUAGES C ASM_NASM)

# 1. Настройка компилятора ассемблера для Windows x64
if(WIN32)
    set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)
endif()

# 2. Получаем список всех подпапок в текущей директории
file(GLOB SUB_DIRECTORIES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*")

# 3. Перебираем все найденные элементы
foreach(DIR ${SUB_DIRECTORIES})
    # Проверяем, что это папка, а не файл
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${DIR})
        
        # Ищем внутри этой папки все файлы .c и .asm
        file(GLOB C_FILES "${DIR}/*.c" "${DIR}/*.cpp")
        file(GLOB ASM_FILES "${DIR}/*.asm")
        
        # Если в папке нашли и Си, и Ассемблер — создаем под них .exe
        if(C_FILES AND ASM_FILES)
            # Имя .exe файла будет совпадать с названием папки (например, Lab6_1.exe)
            set(TARGET_NAME ${DIR})
            
            message(STATUS "Найдено задание: ${TARGET_NAME}")
            
            # Создаем исполняемый файл из всех найденных исходников в этой папке
            add_executable(${TARGET_NAME} ${C_FILES} ${ASM_FILES})
            
            # На всякий случай включаем стандартные предупреждения компилятора
            target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)
        endif()
        
    endif()
endforeach()
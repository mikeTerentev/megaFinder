cmake_minimum_required(VERSION 3.9)

project(MegaFinder)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH /Users/miketerentyev/Qt/5.11.2/clang_64/)
find_package(Qt5Widgets REQUIRED)

add_executable(MegaFinder
        main.cpp
        mainwindow.cpp
        mainwindow.h
        dirlist.cpp
        dirlist.h
        mytreewidget.cpp
        mytreewidget.h
        progressdialog.cpp
        progressdialog.h
        tbufferedreader.cpp
        tbufferedreader.h
        textviewer.cpp
        textviewer.h
        fileindexer.cpp
        fileindexer.h
        trigramsrepository.cpp
        trigramsrepository.h
        trigramssearcher.cpp
        trigramssearcher.h)


qt5_use_modules(MegaFinder Widgets QuickControls2)
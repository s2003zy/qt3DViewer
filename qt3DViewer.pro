######################################################################
# Automatically generated by qmake (3.0) ?? 5? 3 18:20:47 2015
######################################################################
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT *= xml opengl widgets gui
CONFIG -= x86_64

TEMPLATE = app
TARGET = qt3DViewer
INCLUDEPATH += .
CONFIG += c++11
# Input
HEADERS += mainwindow.h \
    viewbase.h \
    mainwindow.h \
    viewfacrtory.h \
    point.h
FORMS += mainwindow.ui
SOURCES += main.cpp \
    viewbase.cpp \
    mainwindow.cpp \
    point.cpp

INCLUDEPATH *= /Users/s2003zy/xcodeProjects/cosegmentation/libQGLViewer-2.6.0 \
            trimesh2/include

LIBS *= -F/Users/s2003zy/Library/Frameworks/ -framework QGLViewer

SOURCES += trimesh2/libsrc/conn_comps.cc  \
        trimesh2/libsrc/diffuse.cc  \
        trimesh2/libsrc/edgeflip.cc  \
        trimesh2/libsrc/faceflip.cc  \
        trimesh2/libsrc/filter.cc  \
        trimesh2/libsrc/GLCamera.cc  \
        trimesh2/libsrc/ICP.cc  \
        trimesh2/libsrc/KDtree.cc  \
        trimesh2/libsrc/lmsmooth.cc  \
        trimesh2/libsrc/overlap.cc  \
        trimesh2/libsrc/remove.cc  \
        trimesh2/libsrc/reorder_verts.cc  \
        trimesh2/libsrc/shared.cc  \
        trimesh2/libsrc/subdiv.cc  \
        trimesh2/libsrc/TriMesh_bounding.cc  \
        trimesh2/libsrc/TriMesh_connectivity.cc  \
        trimesh2/libsrc/TriMesh_curvature.cc  \
        trimesh2/libsrc/TriMesh_grid.cc  \
        trimesh2/libsrc/TriMesh_io.cc  \
        trimesh2/libsrc/TriMesh_normals.cc  \
        trimesh2/libsrc/TriMesh_pointareas.cc  \
        trimesh2/libsrc/TriMesh_stats.cc  \
        trimesh2/libsrc/TriMesh_tstrips.cc


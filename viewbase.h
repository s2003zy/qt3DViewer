#ifndef VIEWBASE_H
#define VIEWBASE_H
#include <QGLViewer/qglviewer.h>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "TriMesh.h"
#include "point.h"
#include <time.h>
#include <stdlib.h>

using namespace trimesh;
using namespace std;
class ViewBase : public QGLViewer {
/*******************************
* the shared data
* each subclass must call the
* construct function of ViewBase
********************************/
public:
    string meshPath;
    TriMesh* mesh;
    vector<Point> center;
protected:
    void readMesh(const std::string path);
    void calculateCenter(TriMesh* m);
    void printMeshInfo(TriMesh* m);
    void moveToCentre(Point &centerPoint, TriMesh* m);
protected:
    virtual void draw();
    virtual void init();
public:
    ViewBase(const string &path);
    ~ViewBase();
};

#endif // VIEWBASE_H

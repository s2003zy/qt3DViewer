#include "viewbase.h"
ViewBase::ViewBase(const string &path) {
    readMesh(path);
}

void ViewBase::readMesh(const std::string path) {
    TriMesh* m = TriMesh::read(path);
    if(!m) {
        exit(1);
    }
    m -> need_faces();
    m -> need_normals();
    m -> need_curvatures();
    m -> need_neighbors();
    printMeshInfo(m);
    calculateCenter(m);
    mesh = m;
}

void ViewBase::calculateCenter(TriMesh* m) {
    Point tmpCenter(0.0, 0.0, 0.0);
    int vSize = m->vertices.size();
    for (int i = 0; i < vSize; i++) {
        tmpCenter.x += m -> vertices[i][0];
        tmpCenter.y += m -> vertices[i][1];
        tmpCenter.z += m -> vertices[i][2];
    }
    tmpCenter.x /= (double) m -> vertices.size();
    tmpCenter.y /= (double) m -> vertices.size();
    tmpCenter.z /= (double) m -> vertices.size();
    center.push_back(tmpCenter);
    moveToCentre(center.back(), m);
}

void ViewBase::moveToCentre(Point &centerPoint, TriMesh* m) {
    int vSize = m->vertices.size();
    for (int i = 0; i < vSize; i++) {
        m -> vertices[i][0] -= centerPoint.x;
        m -> vertices[i][1] -= centerPoint.y;
        m -> vertices[i][2] -= centerPoint.z;
    }
}


void ViewBase::printMeshInfo(TriMesh* m) {
    cout << "Vertices Number : " << m->vertices.size() << endl;
    cout << "Face Number : " << m->faces.size() << endl;

    cout << "Vertex 0 is at " << m->vertices[0] << endl;
    cout << "Face 0 has vertices " << m->faces[0][0] << ", "
         << m->faces[0][1] << ", and " << m->faces[0][2] << endl;

}


void ViewBase::draw() {
    TriMesh* m = mesh;
    int faceNum = m -> faces.size();
    for(int i = 0 ; i < faceNum; i++) {
        glBegin(GL_POLYGON);
            for(int j = 0; j < 3 ; j++) {
                int vId = m->faces[i][j];
                double x = m->vertices[ vId ][0];
                double y  = m->vertices[vId][1];
                double z = m->vertices[vId][2];
                glColor3f(0.8, 0.2, 0.2);
                glNormal3f(m->normals[vId][0], m->normals[vId][1],
                        m->normals[vId][2]);
                glVertex3f(x,y,z);
            }
        glEnd();
    }
}

void ViewBase::init() {
    this -> camera() -> setSceneRadius(100.0);
    this -> camera() -> showEntireScene();
    QColor bgColor(255,255,255);
    this->setBackgroundColor(bgColor);
    this->setForegroundColor(bgColor);
}

ViewBase::~ViewBase() {
    if (mesh) {
        delete mesh;
    }
}

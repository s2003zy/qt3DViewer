#ifndef VIEWFACRTORY_H
#define VIEWFACRTORY_H

#include "viewbase.h"

class ViewFacrtory
{
public:
    static ViewBase* create(string viewName, string path) {
        if (viewName == "normalview") {

            return new ViewBase(path);
        }

        return NULL;
    }
};

#endif // VIEWFACRTORY_H

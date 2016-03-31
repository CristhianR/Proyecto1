/* 
 * File:   xObject.h
 * Author: cristhian
 *
 * Created on March 28, 2016, 9:41 PM
 */

#ifndef XOBJECT_H
#define	XOBJECT_H


class xObject{
    
public:
    void* serialize();
    bool deserialize();
    char* getClassName();
    long getId();
};


#endif	/* XOBJECT_H */


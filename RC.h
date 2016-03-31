/* 
 * File:   RC.h
 * Author: cristhian
 *
 * Created on March 28, 2016, 9:44 PM
 */

#ifndef RC_H
#define	RC_H

class RC
{
    private:
    int count; // Reference count

    public:
    void AddRef()
    {
        // Incrementa el reference count
        count++;
    }

    int Release()
    {
        // Decrementa el reference count y
        // retorna el reference count.
        return --count;
    }
};



#endif	/* RC_H */


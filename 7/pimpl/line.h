
#ifndef __LINE_H__
#define __LINE_H__

class Line{
public:
    Line(int,int,int,int);
    ~Line();
    void printline() const;
    class LineImpl;
private:
    LineImpl *_impl;
};
#endif

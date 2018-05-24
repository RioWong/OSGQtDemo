#include "AutoRotateCallBack.h"
#include <osg/MatrixTransform>

namespace TM
{

    AutoRotateCallBack::AutoRotateCallBack(void)
        :m_dRotateAngle(0)
    {

    }

    AutoRotateCallBack::~AutoRotateCallBack(void)
    {
    }

    void AutoRotateCallBack::operator()(osg::Node* node, osg::NodeVisitor* nv)
    {
        //��������ת���ڵ�
        osg::ref_ptr<osg::MatrixTransform> mt=dynamic_cast<osg::MatrixTransform*>(node);
        //��������
        osg::Matrix mx;
        //����Z����ת
        mx.makeRotate(m_dRotateAngle,osg::Vec3(0.0,0.0,1.0));
        //���þ���
        mt->setMatrix(mx);

        m_dRotateAngle+=0.01;

        //��������
        traverse(node,nv);
    }
}




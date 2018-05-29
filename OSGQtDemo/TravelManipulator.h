
/************************************************************************/
/*                             �Զ�������                                */
/************************************************************************/
#ifndef _TRAVEL_MANIPULATOR_H_
#define _TRAVEL_MANIPULATOR_H_

#include <osgGA/CameraManipulator>

namespace TM
{
    class TravelManipulator :
        public osgGA::CameraManipulator
    {
    public:
        TravelManipulator(void);
        ~TravelManipulator(void);

    public:
        virtual osg::Matrixd getMatrix() const;
        virtual osg::Matrixd getInverseMatrix() const;
        virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& us);

    public:
        void SetSpeed(const double& speed) {m_dSpeed = speed;}
        double GetSpeed() {return m_dSpeed;}

        void SetPosition(const osg::Vec3& pos) {m_vPosition = pos;}
        osg::Vec3 GetPosition() {return m_vPosition;}

    private:
        void ChangePosition(const osg::Vec3& offset);

    private:
        double m_dMouseX;
        double m_dMouseY;
        bool m_bMousePress;

        osg::Vec3 m_vPosition;
        osg::Vec3 m_vRotation;
        double m_dSpeed; // �ƶ��ٶ�

        double m_dScreenAngle;
        bool m_bImpact; // �Ƿ���ײ���

    };
}

#endif // _TRAVEL_MANIPULATOR_H_
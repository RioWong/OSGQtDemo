#ifndef OSGQTDEMO_H
#define OSGQTDEMO_H

#include <QtWidgets/QMainWindow>
#include <Osg/TextureCubeMap>
#include <osgShadow/ShadowedScene>
#include <osg/Sequence>
#include "ui_osgqtdemo.h"
#include "OSGViewWidget.h"

class OSGQtDemo : public QMainWindow
{
    Q_OBJECT

public:
    OSGQtDemo(QWidget *parent = 0);
    ~OSGQtDemo();

private:
    void InitOSGViewWidget();

    /*
     *@brief:   Ϊnode����������ͼ
     *@author:  Timo
     *@date: 2018/05/24
     */
    void CreateTextureForNode(osg::Node* node, osg::Image* img);

    /*
     *@brief:   ����HUD
     *@author:  Timo
     *@date: 2018/05/24
     */
    osg::Camera* CreateHUD(const std::string& hud_text, const unsigned int& width, const unsigned int& height);


    /*
     *@brief:   ����
     *@author:  Timo
     *@date: 2018/05/28
     */
    void CreateCow(osg::Group* root);

    /*
     *@brief:   �����źŲ�
     *@author:  Timo
     *@date: 2018/05/24
     */
    void CreateConnect();

    /*
     *@brief:   ����ս������
     *@author:  Timo
     *@date: 2018/05/28
     */
    void CreateWarScene(osg::Group* root);

    /*
     *@brief:   ���������᷽��鿴
     *@author:  Timo
     *@date: 2018/05/28
     */
    osg::Geode* CreateCoordinateAxis(const osg::Vec3& corner,const osg::Vec3& xdir,const osg::Vec3& ydir,const osg::Vec3& zdir);

    /*
     *@brief:   ��������
     *@author:  Timo
     *@date: 2018/06/05
     */
    void CreateRoom(osgShadow::ShadowedScene* shadow_scene, const osg::ref_ptr<osg::Node>& load_model);


    /*
     *@brief:   ����ǽ��
     *@author:  Timo
     *@date: 2018/06/05
     */
    osg::Geometry* CreateWall(const osg::Vec3& v1,const osg::Vec3& v2,const osg::Vec3& v3,osg::StateSet* stateset);

    /*
     *@brief:   �����ƹ�
     *@author:  Timo
     *@date: 2018/06/05
     */
    osg::Node* CreateLights(osg::BoundingBox& bb,osg::StateSet* rootStateSet);

    /*
     *@brief:   ������Ӱ
     *@author:  Timo
     *@date: 2018/06/05
     */
    osg::ref_ptr<osgShadow::ShadowedScene> CreateShadow();


    /*
     *@brief:   ����֡����
     *@author:  Timo
     *@date: 2018/06/05
     */
    osg::ref_ptr<osg::Sequence> CreateSequence();


    /*
     *@brief:   �Ŵ���
     *@author:  Timo
     *@date: 2018/06/05
     */
    osg::ref_ptr<osg::Node> ScaleNode(osg::Node* node, float target_scale);

    /*
     *@brief:   ������ըЧ��
     *@author:  Timo
     *@date: 2018/06/06
     */
    osg::ref_ptr<osg::Node> CreateBoomEffect();

    /*
     *@brief:   �����Զ��������Ч��
     *@author:  Timo
     *@date: 2018/06/06
     */
    osg::ref_ptr<osg::Node> CreateParticleEffect();

public:

    void ToggleAA();
    void RotateTurrentRight();
    void StopTurrentRight();
    void RotateTurrentLeft();
    void StopTurrentLeft();

    /*
     *@brief:   ��ʾ��̹���뻵̹�˻ص�
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void ToggleAACallback(void* handle_window);

    /*
     *@brief:   ����ת�����ص�
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void RotateTurrentRightCallback(void* handle_window);


    /*
     *@brief:   ����ת�����ص�
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void RotateTurrentLeftCallback(void* handle_window);

    /*
     *@brief:   
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void StopTurrentCallback(void* handle_window);

public slots:
    void OnActionNewProject();
    void OnActionNewWarScene();
    void OnActionLightTest();
    void OnActionClearScene();
    void OnActionSequeceTest();
    void OnActionBoomEffect();
    void OnActionParticleEffect();
    void OnActionAnisotropicLight();
    void OnActionCartoonRender();

protected:
    virtual void resizeEvent(QResizeEvent * event);
    virtual void showEvent(QShowEvent *event);

private:
    Ui::OSGQtDemoClass ui;
    OSGViewWidget* m_pOSGWidget;
    osg::Camera* m_pHudCamera;
    osg::ref_ptr<osg::Group> m_SceneRoot;
    osg::Node* m_pTankNode; // �ڶ���̹��
    bool m_bGoodTank;   // Ĭ����ʾ��̹��
    double m_dTurrentAngle;
};

#endif // OSGQTDEMO_H

#ifndef OSGQTDEMO_H
#define OSGQTDEMO_H

#include <QtWidgets/QMainWindow>
#include <Osg/TextureCubeMap>
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
     *@author:  dgy
     *@date: 2018/05/28
     */
    void CreateWarScene(osg::Group* root);

    /*
     *@brief:   ���������᷽��鿴
     *@author:  dgy
     *@date: 2018/05/28
     */
    osg::Geode* CreateCoordinateAxis(const osg::Vec3& corner,const osg::Vec3& xdir,const osg::Vec3& ydir,const osg::Vec3& zdir);

public:

    void ToggleAA();
    void RotateTurrentRight();
    void StopTurrentRight();
    void RotateTurrentLeft();
    void StopTurrentLeft();

    /*
     *@brief:   ����AA
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void ToggleAACallback(void* handle_window);

    /*
     *@brief:   
     *@author:  Timo
     *@date: 2018/05/28
     */
    static void RotateTurrentRightCallback(void* handle_window);


    /*
     *@brief:   
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

protected:
    virtual void resizeEvent(QResizeEvent * event);
    virtual void showEvent(QShowEvent *event);

private:
    Ui::OSGQtDemoClass ui;
    OSGViewWidget* m_pOSGWidget;
    osg::Camera* m_pHudCamera;
    osg::ref_ptr<osg::Group> m_SceneRoot;
};

#endif // OSGQTDEMO_H

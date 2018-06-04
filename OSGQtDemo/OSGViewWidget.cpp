#include "OSGViewWidget.h"
#include <osgGA/TrackballManipulator>


OSGViewWidget::OSGViewWidget(QWidget* parent /*= 0*/)
    :osgQt::GLWidget(parent),
    m_pTravelManipulator(NULL)
{
    this->setThreadingModel(osgViewer::ViewerBase::SingleThreaded);
    this->_gw = new osgQt::GraphicsWindowQt(this);

//     osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//     camera->setGraphicsContext(this->_gw);
//     camera->setClearColor( osg::Vec4(0.2, 0.2, 0.6, 1.0) );
//     camera->setClearDepth(1.0);
//     camera->setViewport( new osg::Viewport(0, 0, _gw->getTraits()->width, _gw->getTraits()->height) );
//     GLenum buffer = _gw->getTraits()->doubleBuffer ? GL_BACK : GL_FRONT;
//     camera->setDrawBuffer(buffer);
//     camera->setReadBuffer(buffer);
//     camera->setProjectionMatrixAsPerspective(30.f,
//         static_cast<double>(_gw->getTraits()->width)/static_cast<double>(_gw->getTraits()->height),
//         10.0f, 10000.0f );
//     // �Ա���������Camera��ʽ������setGlobalDefaults()��ͼ������Ƚϴ�
//     camera->getOrCreateStateSet()->setGlobalDefaults();
//     this->setCamera(camera.get());

    this->getCamera()->setGraphicsContext(_gw);
    this->getCamera()->setViewport( new osg::Viewport(0, 0, _gw->getTraits()->width, _gw->getTraits()->height));
    this->getCamera()->setClearColor(osg::Vec4(0.2,0.2,0.6, 1.0f));
    GLenum buffer = _gw->getTraits()->doubleBuffer ? GL_BACK : GL_FRONT;
    getCamera()->setDrawBuffer(buffer);
    getCamera()->setReadBuffer(buffer);
    getCamera()->setClearDepth(1.0);

    osgGA::TrackballManipulator* trackBallMpl = new osgGA::TrackballManipulator();
    setCameraManipulator(trackBallMpl);
//     m_pTravelManipulator = TM::TravelManipulator::CreateManipulator(this);
// 
//     setCameraManipulator(m_pTravelManipulator.get());

}


OSGViewWidget::~OSGViewWidget(void)
{
}

void OSGViewWidget::resizeEvent(QResizeEvent* event)
{
    GLWidget::resizeEvent(event);

    if (_gw->getTraits()->height > 0)
    {
        getCamera()->setViewport(0 ,0, _gw->getTraits()->width, _gw->getTraits()->height);
        // ����OSGԴ������������ϵͳӰ��home��ʼ��
        getCamera()->setProjectionMatrixAsPerspective(
            60.f, static_cast<double>(_gw->getTraits()->width)/static_cast<double>(_gw->getTraits()->height), 1.0f, 10000.0f );
    }

    frame();
}

void OSGViewWidget::paintEvent(QPaintEvent* event)
{
    frame();

    update();
}

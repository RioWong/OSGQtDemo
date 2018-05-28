#ifndef _TANK_OPERATOR_H__
#define _TANK_OPERATOR_H__

#include <osg/Node>
#include <osgSim/DOFTransform>
#include <osgSim/MultiSwitch>

class TankOperator : public osg::Referenced
{
public:
    TankOperator(osg::Node* node);
    ~TankOperator(void);

public:
    /*
     *@brief:   ����������ת�Ƕ�
     *@author:  Timo
     *@date: 2018/05/28
     */
    void UpdateTurretRotation();
    
    /*
     *@brief:   ����ǹ�ܽǶ�
     *@author:  Timo
     *@date: 2018/05/28
     */
    void UpdateGunElevation();

    /*
     *@brief:   ��ʾ��̹�˻��̹��
     *@author:  Timo
     *@date: 2018/05/28
     */
    void ShowTank(bool is_good_tank);

private:
    double m_dTurretRotation;
    double m_dGunElevation;

    osgSim::DOFTransform* m_pTankTurretNode;
    osgSim::DOFTransform* m_pTankGunNode;
    osgSim::MultiSwitch* m_pTankMutiSwitch;
};


#endif // _TANK_OPERATOR_H__
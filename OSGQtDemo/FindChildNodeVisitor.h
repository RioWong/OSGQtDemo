#ifndef _FIND_CHILD_NODE_VISITOR_H__
#define _FIND_CHILD_NODE_VISITOR_H__

/************************************************************************/
/*                    ͨ�����Ʋ��ҽ��                                   */
/************************************************************************/

#include <osg/NodeVisitor>

class FindChildNodeVisitor :
    public osg::NodeVisitor
{
public:
    FindChildNodeVisitor(const std::string& node_name);
    ~FindChildNodeVisitor(void);

public:
    virtual void apply(osg::Node& node);
    virtual void apply(osg::Geode& geode);
    virtual void apply(osg::Transform& node);

    void SetSearchName(const std::string& search_name);
    osg::Node* GetFirstNode();

private:
    std::string m_strNodeName;      // �������
    std::vector<osg::Node*> m_FoundNodeList;
};

#endif // _FIND_CHILD_NODE_VISITOR_H__
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

private:
    std::string m_strNodeName;      // �������
    std::vector<osg::Node*> m_FoundNodeList;
};

#endif // _FIND_CHILD_NODE_VISITOR_H__
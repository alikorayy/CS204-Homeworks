#ifndef alikoray_canki_alikoray_hw3_SubSeqsList_h
#define alikoray_canki_alikoray_hw3_SubSeqsList_h


struct SubSeqNode
{
int value;
SubSeqNode * next;
// constructors come here
SubSeqNode::SubSeqNode ()
	:value(0),next(NULL)
	{}
SubSeqNode::SubSeqNode (const int &s, SubSeqNode * link)
	: value(s),next(link)
{}
};
 
struct SubSeqHeadNode
{
int size; // number of elements in the subsequence
SubSeqNode * sHead; // head of the subsequence list
SubSeqHeadNode * next;
// constructors come here
SubSeqHeadNode::SubSeqHeadNode()
	:size(0),sHead(NULL),next(NULL)
{}
SubSeqHeadNode::SubSeqHeadNode(const int&s,SubSeqNode * link,SubSeqHeadNode*link2)
	: size(s),sHead(link),next(link2)
{}
};

class SubSeqsList
{
public:
SubSeqsList(); //default constructor that creates an empty list
// member functions come here
bool IsExistList(int) const;
void Insert2List(int);
bool checkascending(int,SubSeqNode *) const;
void DeleteList(int);
void ClearList(SubSeqNode *);
void LinkedListPrinter();
void SortingList();
void DeleteWholeList();
private:
SubSeqHeadNode * hHead;
// any helper functions you see necessary
};















#endif
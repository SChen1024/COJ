// 链表操作类的 测试
#include <iostream>

using namespace std;

// 定义链表节点 值和指针
struct ListNode
{
    int val;
    ListNode *next;
};

// 定义链表的 增 删 查 改
// CRUD

// 创建链表 //如果已经存在 在链表头部添加新节点
void CreateHead(ListNode *&head, int data)
{
    // 创建 新节点 //申请空间
    ListNode *p = (ListNode*) malloc(sizeof(ListNode));
    p->val = data;
    p->next = nullptr;

    // 如果是一个空链表 直接赋值到head 然后返回
    if(head == nullptr)
    {
        head = p;
        return ;
    }

    // 指向新节点 返回新节点 指针
    p->next = head;
    head = p;
}

// 添加新节点到链表中 // 在链表的指定位置插入新的节点 后插
void AddNode(ListNode * & head,int index,int data)
{
    // 创建 新节点 //申请空间
    ListNode *p = (ListNode*) malloc(sizeof(ListNode));
    p->val = data;
    p->next = nullptr;

    // 如果是一个空链表 直接赋值到head 然后返回
    if(head == nullptr)
    {
        head = p;
        return ;
    }

    // 指向新节点 返回新节点 指针
    p->next = head;
    head = p;
}

// 删除节点 // 判断是否删除成功
bool DeleteNode(ListNode *head, int data)
{
    // 链表为空的情况
    if(nullptr == head)
        return false;

    // 遍历找到相应的节点
    ListNode *p = head;
    ListNode *pre_p = nullptr;  // 记录前一个节点值
    while(p!=nullptr)
    {
        p = p->next;
    }    

    return true;

}

// 查找节点 // 根据值 查找节点
ListNode * FindNodeByData(ListNode *head, int data)
{
    // 返回 节点值等于计数点的值
    ListNode *p = head;
    while(p!=nullptr)
    {
        // 如果 获取到了值 则 直接结束 
        // 如果一直没有找到相应的值的话 一直遍历得到 空指针
        if(p->val == data)
        {
            return p;
        }
        p = p->next;
    }
    // 如果 找不到 则返回空
    return nullptr;
}

// 查找节点 // 根据 索引查找节点
ListNode * FindNodeByIndex(ListNode *head, int index)
{
    // 节点值的话 直接返回
    if(index ==0)
        return head;
    if(index <0)
        return nullptr;

    // 返回 节点值等于 输入值的第一个节点
    ListNode *p = head;
    int cnt =0;
    while(p!=nullptr)
    {
        if(cnt == index)
        {
            return p;
        }

        p = p->next;
        cnt ++;
    }
    // 没有找到 就 返回空
    return nullptr;
}

// 查找节点 // 根据值 查找 index
int FindCntByData(ListNode *head, int data)
{
    ListNode *p = head;
    int index = 0;    // 索引值
    while (p!= nullptr)
    {   
        // 找到相应值 之后 返回计数值
        if(p->val == data)
        {
            return index;
        }
        // 计数累加, 依次后移
        index ++;
        p = p->next;
    }

    // 如果找不到 返回 -1;
    return -1;
    
}

// 根据节点值序号 返回 数据值
int FindIndexByIndex(ListNode *head, int index)
{
    // 节点值的话 直接返回
    if(index ==0)
        return head->val;
    if(index <0)
        return -1;

    // 返回 节点值等于 输入值的第一个节点
    ListNode *p = head;
    int cnt =0;
    while(p!=nullptr)
    {
        if(cnt == index)
        {
            return p->val;
        }

        p = p->next;
        cnt ++;
    }

    // 如果找不到 返回 NULL
    return -1;
    
}


// 更新节点值

// 打印List 所有节点值
void PrintList(ListNode *head)
{
    // 从某个节点开始 打印所有节点的值
    ListNode *p = head; // 临时节点 便于输出 避免 改变 head 值
    while(p != nullptr)
    {
        // cout<<(long)p%65536<<":";        // 输出指针的一个 数字表示
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}


// 反转链表
// ref:[链表反转图文讲解](https://blog.csdn.net/FX677588/article/details/72357389)
// 非递归方式
ListNode * ReverseList(ListNode *head)
{
    // 如果空链表或者 单节点链表
    if(head == nullptr || head->next == nullptr)
        return head;

    // 新建两个节点 P用来遍历head, new_head 为新链表的头
    ListNode *p = head, *new_head = nullptr;

    while(p != nullptr)
    {
        ListNode * tmp = p->next;   // 存储当前节点的指针位置
        p->next = new_head;         // 将当前节点指向新节点的头
        new_head = p;               // 新链表 移动头
        p = tmp;                    // 旧链表指针移动
    }

    // 返回新的节点值
    return new_head;
}

// 不返回操作  非递归 反转链表
void ReverseList2(ListNode * &head)
{
    // 如果空链表或者 单节点链表
    if(head == nullptr || head->next == nullptr)
        return ;

    // 新建两个节点 P用来遍历head, new_head 为新链表的头
    ListNode *p = head, *new_head = nullptr;

    while(p != nullptr)
    {
        ListNode * tmp = p->next;   // 存储当前节点的指针位置
        p->next = new_head;         // 将当前节点指向新节点的头
        new_head = p;               // 新链表 移动头
        p = tmp;                    // 旧链表指针移动
    }

    // 复用 head  指针
    head = new_head;
}

// 递归方式
ListNode * ReverseList_re(ListNode * head)
{
    // 如果空链表或者 单节点链表
    if(head ==nullptr || head->next == nullptr)
        return head;

    // 依次进行每个节点的执行
    ListNode * new_head = ReverseList_re(head->next);

    // 对于每一个节点 反转前后实现
    head->next->next = head;
    head->next = nullptr;

    return new_head;
}


// 主函数 测试 demo 
#define LENGTH 20 
int main(void)
{
    ListNode *head  = nullptr;

    // 生成随机链表
    for(int i=0;i<LENGTH;++i)
        AddNode(head,i,rand()%LENGTH);  // 相应的节点 插入随机值
    PrintList(head);

    // 反转链表 并输出
    head = ReverseList(head);
    PrintList(head);

    // 反转链表 并输出
    ReverseList2(head);
    PrintList(head);

    // 反转链表 并输出 递归实现
    head = ReverseList_re(head);
    PrintList(head);

    cout<<"aw"<<'x'<<endl;

    // system("pause");
    return 0;
}


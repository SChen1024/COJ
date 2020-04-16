#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <stdint.h>

using namespace std;

//定义链表节点
struct LinkNode
{
    uint64_t key;
    uint64_t value;
    LinkNode* next = NULL;
};

// 跳表节点
struct SkipLinkNode
{
    uint64_t key;
    int count;
    LinkNode* pointer = NULL;
    SkipLinkNode* next = NULL;
};

class SkipLinkList
{
public:
    SkipLinkList(int skipStep = 128);
    ~SkipLinkList();
    bool simpleCheck();

public:
    void insert(uint64_t key, uint64_t value);
    void insertSkipNode(SkipLinkNode* pSkipNode,uint16_t key, uint64_t value);  //  后续完成节点插入值
    bool find(uint64_t key, uint64_t &value);

private:
    LinkNode* _listHeader = NULL;
    SkipLinkNode* _skipListHeader = NULL;
    int _skipStep;
    int _itemCount;
};

SkipLinkList::SkipLinkList(int skipStep)
    : _skipStep(skipStep)
    , _listHeader(NULL)
    , _skipListHeader(NULL)
    , _itemCount(0)
{}


SkipLinkList::~SkipLinkList()
{
    LinkNode* node = _listHeader;
    while (node != NULL) {
        LinkNode* toDelNode = node;
        node = node->next;
        delete toDelNode;
    }

    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL) {
        SkipLinkNode* toDelNode = skipNode;
        skipNode = skipNode->next;
        delete toDelNode;
    }
}

bool SkipLinkList::simpleCheck()
{
    uint64_t lastKey = 0;
    int nodeCount = 0;
    LinkNode* node = _listHeader;
    while (node != NULL)
    {
        nodeCount++;
        if (node->key < lastKey)
        {
            return false;
        }
        lastKey = node->key;
        node = node->next;
    }
    if (nodeCount < _skipStep)
    {
        return (_skipListHeader == NULL);
    }

    lastKey = 0;
    int skipNodeCount = 0;
    int expectNodeCount = 0;
    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL)
    {
        skipNodeCount++;
        if (skipNode->key < lastKey)
        {
            return false;
        }
        lastKey = skipNode->key;
        expectNodeCount += skipNode->count;
        skipNode = skipNode->next;
    }
    return nodeCount == expectNodeCount &&
        skipNodeCount >= ((nodeCount + _skipStep - 1) / _skipStep);
}

/** 请完成下面这个函数，实现题目要求的功能 **/
void SkipLinkList::insert(uint64_t key, uint64_t value)
{
    // TODO:
    // 首先在跳表中找到 符合的区域, 然后在左侧依次遍历得到 正确的位置, 如果存在值 替换
    int sKey =0;
    
    // 在跳表中找到节点 // 如果空 则 依次插入 // TODO 
    SkipLinkNode* pSkipNode = _skipListHeader;
    if(pSkipNode ==nullptr) 
    {
        LinkNode* pNode = pSkipNode->pointer;

    }


    // 判断后一个节点与 key的大小 // 保证 pSkipNode 是小于 key 的最大值
    while(pSkipNode->next != nullptr)
    {
        if(pSkipNode->next->key < key)
        {
            pSkipNode = pSkipNode->next;
        }
        else
            break;
    }
    
    // 指向开始的地方
    LinkNode* pNode = pSkipNode->pointer;
    int flg_finded = 0; // 标志找到标志位

    // 如果 需要的话 简历新节点
    // LinkNode *newNode;
    // 依次计数
    for(int i=0;i<pSkipNode->count-1;i++)
    {
        // r如果存在 则直接更新
        if(pNode->next->key == key)
        {
            pNode->next->value = value;
            flg_finded = 1;
            break;
        }
        else if(pNode->next->key>key)
        {
            // 如果超过了 需要找的值
            LinkNode *newNode;
            newNode ->key = key;
            newNode ->value = value;
            newNode ->next = pNode->next;

            pNode->next = newNode;
            
            // 加一 后面检测 是否超过
            pSkipNode->count ++;
        }

        // 如果不是找到的状态 一直找到最后面一个节点
        pNode = pNode->next;
    }

    // 无论如何都找到了末尾, 计算是否超过计数 超过了技术 则调整表
    // 此处需要递归考虑 后续跳表节点值
    if(!flg_finded && pSkipNode->count > _skipStep)
    {
        // while(pSkipNode->count == pSkipNode->next->key < key) )

        if(pSkipNode->next == nullptr)
        {
            SkipLinkNode * newSkipNode;
            newSkipNode->count = 1;
            newSkipNode->pointer = pNode;
            newSkipNode->key = pNode->key;
            newSkipNode->next = nullptr;
        }
        else
        {
            
            pSkipNode->next->key = pNode->key;
            pSkipNode->next->pointer = pNode;
            pSkipNode->next->count ++;          // TODO : 存在问题
        }
        pSkipNode->count -=1;
    }
}

bool SkipLinkList::find(uint64_t key, uint64_t &value)
{
    // TODO:
       // 首先在跳表中找到 符合的区域, 然后在左侧依次遍历得到 正确的位置, 如果存在值 直接返回 true

    
    // 在跳表中找到节点
    SkipLinkNode* pSkipNode = _skipListHeader;
    if(pSkipNode ==nullptr) 
        return false;


    // 判断后一个节点与 key的大小 // 保证 pSkipNode 是小于 key 的最大值
    while(pSkipNode->next != nullptr)
    {
        if(pSkipNode->next->key < key)
        {
            pSkipNode = pSkipNode->next;
        }
        else if(pSkipNode->next->key == key)
            return true;
        else
            break;      // 已经超过 进入 底表查找
    }
    
    // 指向开始的地方
    LinkNode* pNode = pSkipNode->pointer;
    int flg_finded = 0; // 标志找到标志位

    // 如果 需要的话 简历新节点
    LinkNode *newNode;
    // 依次计数
    for(int i=0;i<pSkipNode->count;i++)
    {
        // r如果存在 则直接更新
        if(pNode->next->key == key)
        {
            return true;
        }
        // 如果不是找到的状态 一直找到最后面一个节点
        pNode = pNode->next;
    }


    return false;
}

/** 请完成上面的函数，实现题目要求的功能 **/

vector<string> splitString(const string& text, const string &sepStr) {
    vector<string> vec;
    string str(text);
    string sep(sepStr);
    size_t n = 0, old = 0;
    while (n != string::npos)
    {
        n = str.find(sep,n);
        if (n != string::npos)
        {
            vec.push_back(str.substr(old, n-old));
            n += sep.length();
            old = n;
        }
    }
    vec.push_back(str.substr(old, str.length() - old));
    return vec;
}
template <typename T>
bool stringToInteger(const string& text, T& value) {
    const char* str = text.c_str();
    char* endPtr = NULL;
    value = (T)strtol(str, &endPtr, 10);
    return (endPtr && *endPtr == 0);
}

// 测试跳表 函数
bool testSkipLinkList(string inputParam) {
    vector<string> inputVec = splitString(inputParam, ":");
    if (inputVec.size() != 2 || (inputVec[0] != "list" && inputVec[0] != "count"))
    {
        cout << "input format error!" << endl;
        return false;
    }
    // prepare data
    vector<pair<uint64_t, uint64_t> > keyValueVec;
    if (inputVec[0] == "list") {
        vector<string> kvVec = splitString(inputVec[1], ";");
        for (size_t i = 0; i < kvVec.size(); i++) {
            vector<string> kvStr = splitString(kvVec[i], ",");
            uint64_t key, value;
            if (kvStr.size() != 2 ||
                !stringToInteger<uint64_t>(kvStr[0], key) ||
                !stringToInteger<uint64_t>(kvStr[1], value))
            {
                cout << "key-value list format error!" << endl;
                return false;
            }
            keyValueVec.push_back(make_pair(key, value));
        }
    }

    if (inputVec[0] == "count") {
        uint64_t count;
        if (!stringToInteger<uint64_t>(inputVec[1], count)) {
            cout << "count format error!" << endl;
            return false;
        }
        for (uint64_t i = 0; i < count; i++) {
            keyValueVec.push_back(make_pair(i, i));
        }
        random_shuffle(keyValueVec.begin(), keyValueVec.end());
    }

    uint64_t maxKey = 0;
    uint64_t value;

    SkipLinkList list(4);
    for (size_t i = 0; i < keyValueVec.size(); i++)
    {
        list.insert(keyValueVec[i].first, keyValueVec[i].second);

        // test find
        bool ret = list.find(keyValueVec[i].first, value);
        if (!ret || value != keyValueVec[i].second)
        {
            cout << "test find error!" << endl;
            return false;
        }
        // test replace
        list.insert(keyValueVec[i].first, keyValueVec[i].second + 1);
        ret = list.find(keyValueVec[i].first, value);
        if (!ret || value != keyValueVec[i].second + 1)
        {
            cout << "test replace error!" << endl;
            return false;
        }
        maxKey = max(maxKey, keyValueVec[i].first);
    }

    // test not exist key
    if (list.find(maxKey + 1, value))
    {
        cout << "find not exist error!" << endl;
        return false;
    }
    return list.simpleCheck();
}

int main() {
    bool res;
    string _inputParam;
    getline(cin, _inputParam);
    res = testSkipLinkList(_inputParam);
    if (res)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    return 0;
}
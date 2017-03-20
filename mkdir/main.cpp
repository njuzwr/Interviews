#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 题目说明：
 * 给一组目录名称，计算需要执行的mkdir命令次数（不支持mkdir -p）
 * 例如对于 /foo /foo/bar/  /foor/house 需要执行四次mkdir命令
 */
struct treeNode
{
    // 使用树的结构存储文件目录
    string key;
    vector<treeNode*> childs;
    static int count; //每建立一个节点，次数加一
    treeNode(string key1) :key(key1)
    {
        count++;
    }
};
int treeNode::count = 0;
void split(const string& key, vector<string>& s)
{
    // 将key按照'/'分割，存放在vector<string>中
    string::size_type pos1 = 0;
    string::size_type pos2 = 1;
    while (pos1 != string::npos)
    {
        pos2 = key.find('/', pos1 + 1);
        s.push_back(key.substr(pos1 + 1, pos2 - pos1 - 1)); //第二个参数是子字符串长度
        pos1 = pos2;
    }
}

void insert(const string& key, treeNode* root)
{
    vector<string> tmp;
    split(key, tmp);
    treeNode* child = root;
    for (int i = 0; i < tmp.size(); i++)
    {
        child = root;
        for (int j = 0; j < root->childs.size(); j++)
        {
            if (root->childs[j]->key == tmp[i])
            {
                root = root->childs[j];
                break;
            }
        }
        if (child == root)
        {
            root->childs.push_back(new treeNode(tmp[i]));
            root = root->childs.back();
        }
        else
            child = root;
    }
}

int main() {
    string str;
    treeNode* data = new treeNode("/");
    vector<string> input;
    while(cin >> str)
        input.push_back(str);
    for (const auto i : input)
        insert(i, data);
    cout << treeNode::count-1 << endl; // 减去根节点
    return 0;
}



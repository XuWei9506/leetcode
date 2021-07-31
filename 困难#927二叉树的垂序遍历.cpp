class Solution {
public:

    struct cmp {
    bool operator()(const vector<int> v1, const vector<int> v2)const
    {
        if(v1[1] != v2[1])
        {
            return v1[1] < v2[1];
        }
        else
        {
            return v1[0] < v2[0];
        }
    }
    };

    void travel(TreeNode* root, int row, int col)
    {
        if(root)
        {
            vector<int> ovec{row, col};
            m_resultMap[ovec].push_back(root->val);
            travel(root->left, row + 1, col - 1);
            travel(root->right, row + 1, col + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //先中序遍历一遍
        travel(root, 0, 0);

        vector<vector<int>> oResultvec;
        std::map<vector<int>, vector<int>, cmp>::iterator it = m_resultMap.begin();

        std::map<int, vector<int>> oMap;
        while(it != m_resultMap.end()) 
        {
            vector<int> oVec = it->second;
            std::sort(oVec.begin(), oVec.end(), less<int>());

            for(auto& num : oVec)
            {
                oMap[it->first.at(1)].push_back(num);
            }
            it++;
        }   

        std::map<int, vector<int>> ::iterator it2 = oMap.begin();
        while(it2 != oMap.end())
        {
            oResultvec.push_back(it2->second);
            it2++;
        }

        return oResultvec;
    }   
private:
    std::map<vector<int>, vector<int>, cmp> m_resultMap;
};
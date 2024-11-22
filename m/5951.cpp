#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int detectHumanGenome(string allowed, vector<string>& datas) {
        int time = 0, xx = 0;
        bool compare = false;

        //多少單字
        for(int i = 0 ; i < datas.size() ; i++){
            // cout<<i<<endl;
            // cout<<"datas["<<i<<"]:"<<datas[i]<<endl;

            //每個單字有多少字母
            for(int j = 0 ; j < datas[i].size() ; j++){
                //每個單字的字母跟allowed的字母比較
                xx=0;
                for(int k = 0 ; k <  allowed.size() ; k++ ){
                    // cout<<"---------"<<endl;
                    // cout<<datas[i][j] << " " << allowed[k];;
                    if(datas[i][j] == allowed[k]){
                        compare = true;
                        // cout<< " " << compare << endl;
                        break;
                    }else{
                        compare = false;
                        xx++;
                    }
                    // cout<< " " << compare << endl;
                    if(compare == true){
                        break;
                    }
                }
                //cout<<xx<<" : "<<allowed.size()<<endl;
                if(xx==allowed.size())
                    break;

            }
            
            if(compare == true)
                time++;

            // cout<<endl;
            // cout<<"time: "<<time<<endl;
            // cout<<endl;
           
        }
        //compare = false;
        return time;
    }
    
};

int main(int argc, char const *argv[]){
    string allowed, data;
    vector<string> datas;
    int num, ans = 0;
    cin >> allowed >> num;

    for (int i = 0; i < num; i++) {
        cin >> data;
        datas.push_back(data);
    }

    Solution sol;
    ans = sol.detectHumanGenome(allowed, datas);
    cout << ans;

    //確認輸入的字
    // cout<<"----------"<<endl;
    // cout<<allow;
    // for(auto i:words){
    //     cout<<i<<" ";
    // }
    return 0;
}

//解法2 from 林易佳 (需include<unordered_set)
//class Solution {
//public:
//    int detectHumanGenome(string& allowed, vector<string>& datas) {
//        int times = 0;
//        unordered_set<char> sets;
//        for (char c : allowed) {
//            sets.insert(c);
//        }
//
//        for (string str : datas) {
//            bool isPass = true;
//            for (char c : str) {
//                if (sets.find(c) == sets.end()) {
//                    isPass = false;
//                    break;
//                }
//            }
//            if (isPass) {
//                times++;
//            }
//        }
//        return times;
//    }
//};

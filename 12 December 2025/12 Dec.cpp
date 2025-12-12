class Solution {
public:
class compare{
public:
bool operator()(vector<string>&a,vector<string>&b){
    int at=stoi(a[1]);
    int bt=stoi(b[1]);
    if(at!=bt)return at<bt;
    if(b[0]=="OFFLINE")return false;
    return true;
    }
};
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n=numberOfUsers;
        vector<int> cnt(n);
        vector<int>nxt(n);
        sort(events.begin(),events.end(),compare());
        for(auto &ev:events){
            int curr=stoi(ev[1]);
            if(ev[0]=="MESSAGE"){
                if(ev[2]=="ALL"){
                    for(int i=0;i<n;i++){
                        cnt[i]++;
                    }
                }
                else if(ev[2]=="HERE"){
                    for(int i=0;i<n;i++){
                        if(nxt[i]<=curr){
                            cnt[i]++;
                        }
                    }
                }
                else{
                    int idx=0;
                    for(int i=0;i<ev[2].size();i++){
                        if(isdigit(ev[2][i])){
                            idx=idx*10+(ev[2][i]-'0');
                        }
                        if(i+1==ev[2].size()||ev[2][i+1]==' '){
                            cnt[idx]++;
                            idx=0;
                        }
                    }
                }
            }
            else{
                int idx=stoi(ev[2]);
                nxt[idx]=curr+60;
            }
        }
        return cnt;
    }
};
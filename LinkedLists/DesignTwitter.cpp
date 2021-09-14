class Twitter {
public:
    /** Initialize your data structure here. */
    map<int,vector<pair<int,int>>> tweets;
    map<int,set<int>> following;
    int time=0;
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userid, int tweetid) {
        tweets[userid].push_back({time++,tweetid});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int u) {
        vector<int> res;
        priority_queue<pair<int,int>> z;
        int cnt=0;
        for(auto it:tweets[u])
        {
            cnt++;
            z.push({it.first,it.second});
            if(cnt>10)
                break;
        }
        for(auto it:following[u])
        {
            int id=it;
            cnt=0;
            for(auto itr:tweets[id])
            {
                cnt++;
                z.push({itr.first,itr.second});
                if(cnt>10)
                    break;
            }
        }
        cnt=0;
        while(!z.empty()&&cnt<10)
        {
            res.push_back(z.top().second);
            z.pop();
            cnt++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int a, int b) {
        following[a].insert(b);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int a, int b) {
        following[a].erase(b);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

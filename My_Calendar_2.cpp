class MyCalendarTwo {
    vector<pair<int,int>>interval;
    vector<pair<int,int>>overlap;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //if there is a overalp on already existing over,return false
        for(auto i:overlap)
        {
            if(start < i.second && end > i.first)
                return false;
        }
        
        // continue with finding the right range and inserting in the overlap array
        // case - insert (15,25) - into [(10,20)] - overlap will be (15,25)
        for(auto i:interval)
        {
            if(start < i.second && end > i.first)
                overlap.push_back(make_pair(max(i.first,start),min(i.second,end)));
        }
        interval.push_back(make_pair(start,end));
        return true;
        
    }
};
#include<bits/stdc++.h>

using namespace std;

vector<pair<double, double> >values;
vector<int>total;
double t,w,amount=-1.0;



int hunter(int i, double recover, double time, int steps)
{
    if(t<time+total[i])
    {
        cout<<recover<<" "<<steps<<endl;
        return 0;
    }
    else{
        cout<<steps<<" "<<i<<" "<<time+total[i]<<endl;
        time+=total[i];
        recover+=values[i].second;
    }

    for(i+=1; i<total.size(); ++i )
    {
        hunter(i+1, recover,time, steps+1);
    }
}


int main()
{

    while(cin>>t>>w)
    {
        double treasure, d, g;
        cin>>treasure;
        values.assign(treasure, pair<double,double>());
        total.assign(treasure,0);
        for(int i=0; i<treasure; ++i)
        {
            cin>>d>>g;
            values[i]=make_pair(d,g);
            total[i]=(w*(d*3));
        }
        hunter(0,0.0,0.0,0);
    }


    return 0;
}

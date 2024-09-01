#include<bits/stdc++.h>
using namespace std;
#define ll long long ;
vl seg;
vl lazy;
void build(int idx,int low,int high)
{
    if(low==high)
    {
        seg[idx]=arr[low];
        return;
    }
    long long mid=(low+high)>>1;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
}
long long query(ll idx,ll low,ll high,ll l,ll r)
{
    if(low>=l && high<=r)
    {
        return seg[ind];
    }
    if(high<l || low>l) return INT_MIN;
    ll mid=(low+high)>>1;
    ll left=query(2*idx+1,low,mid,l,r);
    ll right=query(2*idx+2,mid+1,high,l,r);
    return min(left,right);
}
void rangeupdate(ll ind,ll low,ll high,ll l,ll r,ll val)
{
    if(lazy[idx]!=0)
    {
        seg[idx]+=(lazy[idx]*(high-low+1));
        if(low!=high)
        {
            lazy[2*idx+1]=lazy[idx];
            lazy[2*idx+2]=lazy[idx];
        }
        lazy[idx]=0;
        return ;
    }
    if(l>high || r<low || low>high) return ;
    if(low>=l && high<=r)
    {
        seg[idx]+=(high-low+1)*val;
        if(low!=high)
        {
            lazy[2*idx+1]+=val;
            lazy[2*idx+2]+=val;
        }
        return ;
    }
    ll mid=(low+high)>>1;
    rangeupdate(2*idx+1,low,mid,l,r,val);
    rangeupdate(2*idx+2,mid+1,high,l,r,val);
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);

}
ll query_Sum(ll ind,ll low,ll high,ll l,ll r)
{
       if(lazy[idx]!=0)
    {
        seg[idx]+=(lazy[idx]*(high-low+1));
        if(low!=high)
        {
            lazy[2*idx+1]=lazy[idx];
            lazy[2*idx+2]=lazy[idx];
        }
        lazy[idx]=0;
        return ;
    }
    if(l>high || r<low || low>high) return 0;
    if(low>=l && high<=r)
    {
        return seg[idx];
    }
    return query_Sum(2*idx+1,low,mid,l,r)+query_Sum(2*idx+2,mid+1,high,l,r);

}

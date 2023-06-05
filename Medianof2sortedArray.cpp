double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
  if(A.size()>B.size()) return findMedianSortedArrays(B,A);
  int l=0,h=A.size();
  int n=A.size(),m=B.size();
  if(n==0)
  {
      if(m%2==1) return B[m/2];
      else return double(B[m/2]+B[m/2-1])/2;
  }
  if(m==0)
  {
      if(n%2==1) return A[n/2];
      else return double(A[n/2]+A[n/2-1])/2;
  }
  while(h>=l)
  {
      
      int c1=l+(h-l)/2;
      int c2=(n+m+1)/2-c1;

      int l1=c1==0?INT_MIN:A[c1-1];
      int l2=c2==0?INT_MIN:B[c2-1];
      
      int r1=c1==n?INT_MAX:A[c1];
      int r2=c2==m?INT_MAX:B[c2];
      
      
      if(r2>=l1 && r1>=l2)
      {
          
          if((m+n)%2==0) return double(max(l1,l2)+min(r1,r2))/2;
          else return double(max(l1,l2));
          
      }
      else if(l1>r2) h=c1-1;
      else l=c1+1;
      
      
      
      
  }
  return -1;
}

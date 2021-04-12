vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0;
            int j=0;
            int k=0;
            
            vector<int> ans;
            while(i<n1 and j<n2 and k<n3)
            {
                int x=min({A[i],B[j],C[k]});
                if(A[i]==x and B[j]==x and C[k]==x)
                {
                    if(ans.size()==0 or ans.back()!=x)
                    ans.push_back(x);
                }
                
                if(A[i]==x)
                i++;
                
                if(B[j]==x)
                j++;
                
                if(C[k]==x)
                k++;
            }
            return ans;
        }
void rearrange(int a[], int n) {
	    int l=0;
	    int r=0;
	    
	    while(r<n)
	    {
	        if(a[r]<0)
	        {
	            swap(a[l],a[r]);
	            l+=2;
	        }
	        else{
	            r++;
	        }
	        if(l>r)
	        r=l;
	    }
	}
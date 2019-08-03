#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 绘制 n层 矩形
void plotCross(vector<vector<int>> &vec,int nx,int ny,int n)
{
  if(n==1)
    vec[nx][ny] = 'o';
  else
  {
    // 递归绘制 底层区域
  	int i = pow(3,n-2);
    plotCross(vec,nx,ny,n-1);
    plotCross(vec,nx-i,ny,n-1);
    plotCross(vec,nx+i,ny,n-1);
    plotCross(vec,nx,ny-i,n-1);
    plotCross(vec,nx,ny+i,n-1);
  
  }
    
    
}

// 将结果输出 出来
void coutVec(char[][] data,int W,int W)
{
  // 判断结果 是否异常
  if(vec.size()==0)return ;
  if(vec[0].size() == 0) return ;
  // 循环输出
	for(int i=0;i<vec.size();++i)
    {
      for(int j=0;j<vec[0].size();++j)
        cout<<vec[i][j];
      cout<<endl;
    }
}

int main(void)
{
  int T =0;
  cin>>T;
  
  // 依次执行 执行判定
  int n=0;
  while(cin>>n)
  {
    // 初始化 数组 宽度和中点都 计算出来
    int W=pow(3,n-1);
    int center = (W-1)/2;
    vector<vector<char>> VecN(W,vector<char>(W,''));
    char dataN[W][W];
    
    plotCross(dataN,center,center,n);

    cout<<"Case #"<<n<<":"<<endl;
    coutVec(dataN,W,W);    
    
  }
  
 
  return 0;
}


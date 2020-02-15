

// 图像处理（二）Seam Carving算法-Siggraph 2007
// [参考链接](https://blog.csdn.net/hjimce/article/details/44916869)

// 1. 
	//先找出图片最底部的一行中，能量最小的像素点作为起始点
	int min_x = 0;
	int width = (*Source).Width();
	int height = (*Source).Height();
	for( int x = 0; x < width; x++ )
	{
		if( (*Source)(x,height-1)->energy < (*Source)(min_x,height-1)->energy )
		{
			min_x = x;
		}
	}

// 2. 

//min_x是图片最底部的一行的能量值最小的像素点 因此遍历的时候，要往上寻找
void Generate_Path( CML_image_ptr * Energy, int min_x, int * Path )
{
	int min;
	int x = min_x;//起始行的能量最小点
	int height = (*Energy).Height();
//从底部往上寻找最小能量线
	for( int y = height - 1; y >= 0; y-- ) //从下往上
	{
		min = x; //首个顶点迭代更新
		//计算上一行中  三个邻接像素中能量值最小的像素点 作为上一行的能量最小点
		int Maxy=  Get_Max( Energy, min, y );
		if( Get_Max( Energy, x-1, y ) < Maxy ) //
		{
			min = x - 1;
		}
		if( Get_Max( Energy, x+1, y ) < Maxy ) //up-right
		{
			min = x + 1;
		}
		Path[y] = min;
		x = min;
	}
}


// 移除能量线
int height=(*Source).Height();
	int width=(*Source).Width();
	//移除函数
	for( int y =0; y < height; y++ )
	{
		int remove = (Path)[y];
		(*(Source))(remove,y)->removed = true;
		//移除的时候 为了让图像看起来自然，需要在移除缝线的地方进行平均，假设移除坐标为P(x,y),那么
		//移除后P(x-1,y)的像素值为P(x-1,y)与P(x,y)的像素值的平均
		//P(x+1,y)的像素值为P(x-1,y)与P(x,y)的像素值的平均，然后才能把P(x+1,y)移动到P(x,y)的位置
		if( (remove - 1) > 0 )
		{
			if( (*(Source))(remove,y)->weight >= 0 )
			{
				(*(Source))(remove-1,y)->image = Average_Pixels( (*(Source))(remove,y)->image,
					(*(Source)).Get(remove-1,y)->image );
			}
			(*(Source))(remove-1,y)->gray = Grayscale_Pixel( &(*(Source))(remove-1,y)->image );
		}

		if( (remove + 1) < (*(Source)).Width() )
		{
			if( (*(Source))(remove,y)->weight >= 0 ) 
			{
				(*(Source))(remove+1,y)->image = Average_Pixels( (*(Source))(remove,y)->image,
					(*(Source)).Get(remove+1,y)->image );
			}
			(*(Source))(remove+1,y)->gray = Grayscale_Pixel( &(*(Source))(remove+1,y)->image );
		}
		(*(Source)).Shift_Row( remove + 1, y, -1 );
	}
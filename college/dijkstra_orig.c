#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODE_NUM 10 /* 総ノード数 */
#define MAX 9999 /* 無限大に相当する数 */

#define FLAG 0 /* Dijkstraのテストの場合は0に、シミュレーション評価を行う場合は1にする */

int main()
{
/* Dijkstraのアルゴリズム部分で必要な変数 */
  int graph[NODE_NUM][NODE_NUM]; /* 距離行列 */ 
  int path[NODE_NUM]; /* 前ノード表 */
  int dist[NODE_NUM]; /* 距離を格納 */
  int chk[NODE_NUM]; /* 最短距離確定のフラグ */
  int tmp_node, tmp_dist; /* 注目しているノードとそこまでの最短距離 */
  int src, dest; /* 始点・終点ノード */
  int a, b, c, d, i, j;
  int fin; /* 未確定ノードが残っているかどうかのフラグ */
  FILE *fp; /* 距離の入ったファイルを示すポインタ */

  /* シミュレーション評価の部分で必要な変数 */
  int link[NODE_NUM][NODE_NUM]; /* リンク容量 */
  int bandwidth[NODE_NUM][NODE_NUM]; /* リンクの空き容量 */
  int miss; /* 呼損を表すフラグ */
  int success; /* 確立できた通信回数 */
  int sum_success; /* 確立できた通信回数の合計 */
  int sim_time; /* 評価の回数をカウント */



/*
距離行列の作成
*/
  for(i=0; i<NODE_NUM; i++){
    for(j=0; j<NODE_NUM; j++){
      graph[i][j] = MAX; /* 接続されていないノード間の距離をMAXにする */
      link[i][j] = -1; /* 接続されていないノード間のリンク容量を-1にする */
      if(i==j){graph[i][j] = 0; link[i][j] = -1;}/* そのノード自身への距離は0とし、リンク容量は-1とする */
    }
  }
  fp=fopen("./distance.txt", "r");
  while(fscanf(fp, "%d %d %d %d", &a, &b, &c, &d) != EOF) /* EOFまで4つ組を読み込む */
    {
      graph[a][b]=c; /* 接続されているノード間の距離を設定 */
      graph[b][a]=c; /* 逆方向も等距離と仮定 */
      link[a][b]=d; /* 接続されているノード間のリンクを設定 */
      link[b][a]=d; /* 逆方向も同じ容量と仮定 */
    }
  fclose(fp);

/* 
始点・終点ノードを標準入力から得る (評価の場合は、実行しない)
*/
  if (FLAG == 0){
    printf("Source Node?(0-%d)", NODE_NUM-1);
    fscanf(stdin, "%d", &src);
    printf("Destination Node?(0-%d)", NODE_NUM-1);
    fscanf(stdin, "%d", &dest);
  }

  if (FLAG == 1) srand((unsigned)time(NULL)); /* 乱数の初期化, これ以降、rand()で乱数を得ることができる */



/****************************/
/* シミュレーション評価開始 */
/****************************/

  success = 0; sum_success = 0; /* 評価指標を初期化 */
  for (sim_time=0; sim_time<1000; sim_time++){
    miss = 0; /* 空きリンクが存在しない場合のフラグをOFFにする */
    success = 0; /* 確立できた通信回数を初期化する */

    for (i=0; i<NODE_NUM; i++){ /* 全リンクの空き容量を初期状態に戻す */
      for (j=0; j<NODE_NUM; j++){
        
      }
    }



    while(miss == 0){ /* 呼損が発生するまで繰り返す
      /* 評価の場合、送受信ノードをランダムに決定 */
      if (FLAG == 1){
        /* ランダムに送受信ノードを決定 */


        printf("src=%d, dest=%d\n", src, dest); /* 送受信ノードを表示 */
        if (src==dest) printf("送受信ノードが一致している\n");
      }



      /****************************************/
      /* ここからdijkstraのアルゴリズムを記述 */
      /* 最初はこの部分を記述し、作成すること */
      /****************************************/

      /*
      初期化
      */
      for(i=0; i<NODE_NUM; i++){ /* 何も確定していない状態にする */
        dist[i] = MAX;
        chk[i] = 0;
        path[i] = NODE_NUM;
      }
      path[src] = src; /* 始点ノードへの経路上の前ノードはそれ自身とする */
      dist[src] = 0; /* 始点ノード自身への距離は0である */
      chk[src] = 1; /* 始点ノードへの最短距離は確定 */
      tmp_node = src; /* 始点ノードから探索を始める */
      fin = 0;


      /* 
      経路探索
      */

      /* 2. 送信ノードに接続されている全てのノードについて、接続リンクの長さを送信ノードからの長さとする */







      /* 3. 送信ノードに接続されている全てのノードうち、最短の距離をもつノードを確定とする */


      while(fin==0){ /* finフラグが立つまで繰り返す */
        /* 4.*/
        /* 確定したノードに接続している全てのノードについて */
        /* srcからtmp_nodeまでの距離とtmp_nodeから現在考えているノードiまでの距離を計算 */
        /* これまでの距離より短ければ */
        /* distとpathを更新する */






        /* 5. まだ確定していないノードのうち、送信ノードからの距離が最短のノードを確定とする*/








        if(chk[dest] == 1) fin = 1; /* 終点ノードへの最短距離が確定したら終了 */
      }

      /* 
      結果出力(Dijkstra作成時のみ実行する)
      */
      if(FLAG == 0){
        if(dist[dest]>=MAX){
          printf("No path from node%d to node%d.\n",src,dest);
        }else{
          printf("Shortest path from node%d to node%d is as follows.\n",src,dest);
          printf("%d <- ",dest);
          i=dest;
          for(i=path[i]; i!=src; i=path[i]){/* 前ノード表を辿る */
            printf("%d <- ",i);
          }
          printf("%d\n",src);
          printf("Shortest distance is %d.\n", dist[dest]);
        }
        return 0; /* Dijkstraの作成時は結果を出力したらプログラムを終了する */
      }

      /************************************/
      /* ここまでがdijkstraのアルゴリズム */
      /************************************/

      /**********************************************************************/
      /* この下にdijkstraで決定した経路を評価するためのプログラムを記述する */
      /**********************************************************************/

/*      2-(a) その経路上の全てのリンクに空き容量がある場合、それらを1Mbpsだけ
      減少させ、「確立できた通信回数」を1増やす
*/

/*
      2-(b) その経路上に空き容量のないリンクが存在する場合、呼損とし、
      その時点までの「確立できた通信回数」をsum_successに足して、while文をbreakする
*/



    } /* while(1) */
  } /* 1～3の手続きを1000回行うためのfor文 */


  /*
  シミュレーション評価の結果出力
  */
  printf("\naverage = %f\n", sum_success / 1000.0); /* 初めて呼損が起こるまでに確立できた通信回数の平均を表示 */
  return 0;
}



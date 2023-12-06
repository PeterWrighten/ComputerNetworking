#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODE_NUM 10 /* ���m�[�h�� */
#define MAX 9999 /* ������ɑ������鐔 */

#define FLAG 0 /* Dijkstra�̃e�X�g�̏ꍇ��0�ɁA�V�~�����[�V�����]�����s���ꍇ��1�ɂ��� */

int main()
{
/* Dijkstra�̃A���S���Y�������ŕK�v�ȕϐ� */
  int graph[NODE_NUM][NODE_NUM]; /* �����s�� */ 
  int path[NODE_NUM]; /* �O�m�[�h�\ */
  int dist[NODE_NUM]; /* �������i�[ */
  int chk[NODE_NUM]; /* �ŒZ�����m��̃t���O */
  int tmp_node, tmp_dist; /* ���ڂ��Ă���m�[�h�Ƃ����܂ł̍ŒZ���� */
  int src, dest; /* �n�_�E�I�_�m�[�h */
  int a, b, c, d, i, j;
  int fin; /* ���m��m�[�h���c���Ă��邩�ǂ����̃t���O */
  FILE *fp; /* �����̓������t�@�C���������|�C���^ */

  /* �V�~�����[�V�����]���̕����ŕK�v�ȕϐ� */
  int link[NODE_NUM][NODE_NUM]; /* �����N�e�� */
  int bandwidth[NODE_NUM][NODE_NUM]; /* �����N�̋󂫗e�� */
  int miss; /* �đ���\���t���O */
  int success; /* �m���ł����ʐM�� */
  int sum_success; /* �m���ł����ʐM�񐔂̍��v */
  int sim_time; /* �]���̉񐔂��J�E���g */



/*
�����s��̍쐬
*/
  for(i=0; i<NODE_NUM; i++){
    for(j=0; j<NODE_NUM; j++){
      graph[i][j] = MAX; /* �ڑ�����Ă��Ȃ��m�[�h�Ԃ̋�����MAX�ɂ��� */
      link[i][j] = -1; /* �ڑ�����Ă��Ȃ��m�[�h�Ԃ̃����N�e�ʂ�-1�ɂ��� */
      if(i==j){graph[i][j] = 0; link[i][j] = -1;}/* ���̃m�[�h���g�ւ̋�����0�Ƃ��A�����N�e�ʂ�-1�Ƃ��� */
    }
  }
  fp=fopen("./distance.txt", "r");
  while(fscanf(fp, "%d %d %d %d", &a, &b, &c, &d) != EOF) /* EOF�܂�4�g��ǂݍ��� */
    {
      graph[a][b]=c; /* �ڑ�����Ă���m�[�h�Ԃ̋�����ݒ� */
      graph[b][a]=c; /* �t�������������Ɖ��� */
      link[a][b]=d; /* �ڑ�����Ă���m�[�h�Ԃ̃����N��ݒ� */
      link[b][a]=d; /* �t�����������e�ʂƉ��� */
    }
  fclose(fp);

/* 
�n�_�E�I�_�m�[�h��W�����͂��瓾�� (�]���̏ꍇ�́A���s���Ȃ�)
*/
  if (FLAG == 0){
    printf("Source Node?(0-%d)", NODE_NUM-1);
    fscanf(stdin, "%d", &src);
    printf("Destination Node?(0-%d)", NODE_NUM-1);
    fscanf(stdin, "%d", &dest);
  }

  if (FLAG == 1) srand((unsigned)time(NULL)); /* �����̏�����, ����ȍ~�Arand()�ŗ����𓾂邱�Ƃ��ł��� */



/****************************/
/* �V�~�����[�V�����]���J�n */
/****************************/

  success = 0; sum_success = 0; /* �]���w�W�������� */
  for (sim_time=0; sim_time<1000; sim_time++){
    miss = 0; /* �󂫃����N�����݂��Ȃ��ꍇ�̃t���O��OFF�ɂ��� */
    success = 0; /* �m���ł����ʐM�񐔂����������� */

    for (i=0; i<NODE_NUM; i++){ /* �S�����N�̋󂫗e�ʂ�������Ԃɖ߂� */
      for (j=0; j<NODE_NUM; j++){
        
      }
    }



    while(miss == 0){ /* �đ�����������܂ŌJ��Ԃ�
      /* �]���̏ꍇ�A����M�m�[�h�������_���Ɍ��� */
      if (FLAG == 1){
        /* �����_���ɑ���M�m�[�h������ */


        printf("src=%d, dest=%d\n", src, dest); /* ����M�m�[�h��\�� */
        if (src==dest) printf("����M�m�[�h����v���Ă���\n");
      }



      /****************************************/
      /* ��������dijkstra�̃A���S���Y�����L�q */
      /* �ŏ��͂��̕������L�q���A�쐬���邱�� */
      /****************************************/

      /*
      ������
      */
      for(i=0; i<NODE_NUM; i++){ /* �����m�肵�Ă��Ȃ���Ԃɂ��� */
        dist[i] = MAX;
        chk[i] = 0;
        path[i] = NODE_NUM;
      }
      path[src] = src; /* �n�_�m�[�h�ւ̌o�H��̑O�m�[�h�͂��ꎩ�g�Ƃ��� */
      dist[src] = 0; /* �n�_�m�[�h���g�ւ̋�����0�ł��� */
      chk[src] = 1; /* �n�_�m�[�h�ւ̍ŒZ�����͊m�� */
      tmp_node = src; /* �n�_�m�[�h����T�����n�߂� */
      fin = 0;


      /* 
      �o�H�T��
      */

      /* 2. ���M�m�[�h�ɐڑ�����Ă���S�Ẵm�[�h�ɂ��āA�ڑ������N�̒����𑗐M�m�[�h����̒����Ƃ��� */







      /* 3. ���M�m�[�h�ɐڑ�����Ă���S�Ẵm�[�h�����A�ŒZ�̋��������m�[�h���m��Ƃ��� */


      while(fin==0){ /* fin�t���O�����܂ŌJ��Ԃ� */
        /* 4.*/
        /* �m�肵���m�[�h�ɐڑ����Ă���S�Ẵm�[�h�ɂ��� */
        /* src����tmp_node�܂ł̋�����tmp_node���猻�ݍl���Ă���m�[�hi�܂ł̋������v�Z */
        /* ����܂ł̋������Z����� */
        /* dist��path���X�V���� */






        /* 5. �܂��m�肵�Ă��Ȃ��m�[�h�̂����A���M�m�[�h����̋������ŒZ�̃m�[�h���m��Ƃ���*/








        if(chk[dest] == 1) fin = 1; /* �I�_�m�[�h�ւ̍ŒZ�������m�肵����I�� */
      }

      /* 
      ���ʏo��(Dijkstra�쐬���̂ݎ��s����)
      */
      if(FLAG == 0){
        if(dist[dest]>=MAX){
          printf("No path from node%d to node%d.\n",src,dest);
        }else{
          printf("Shortest path from node%d to node%d is as follows.\n",src,dest);
          printf("%d <- ",dest);
          i=dest;
          for(i=path[i]; i!=src; i=path[i]){/* �O�m�[�h�\��H�� */
            printf("%d <- ",i);
          }
          printf("%d\n",src);
          printf("Shortest distance is %d.\n", dist[dest]);
        }
        return 0; /* Dijkstra�̍쐬���͌��ʂ��o�͂�����v���O�������I������ */
      }

      /************************************/
      /* �����܂ł�dijkstra�̃A���S���Y�� */
      /************************************/

      /**********************************************************************/
      /* ���̉���dijkstra�Ō��肵���o�H��]�����邽�߂̃v���O�������L�q���� */
      /**********************************************************************/

/*      2-(a) ���̌o�H��̑S�Ẵ����N�ɋ󂫗e�ʂ�����ꍇ�A������1Mbps����
      ���������A�u�m���ł����ʐM�񐔁v��1���₷
*/

/*
      2-(b) ���̌o�H��ɋ󂫗e�ʂ̂Ȃ������N�����݂���ꍇ�A�đ��Ƃ��A
      ���̎��_�܂ł́u�m���ł����ʐM�񐔁v��sum_success�ɑ����āAwhile����break����
*/



    } /* while(1) */
  } /* 1�`3�̎葱����1000��s�����߂�for�� */


  /*
  �V�~�����[�V�����]���̌��ʏo��
  */
  printf("\naverage = %f\n", sum_success / 1000.0); /* ���߂Čđ����N����܂łɊm���ł����ʐM�񐔂̕��ς�\�� */
  return 0;
}



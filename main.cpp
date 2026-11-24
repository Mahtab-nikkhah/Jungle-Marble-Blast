#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include<ctime>
#include <fstream>
#define PI 3.1415
#define W 1280
#define H 800
using namespace std;

void textman(SDL_Renderer *renderer,int x,int y,const char * text,int font_size,int R,int G,int B, int A)
{
    TTF_Init();
    SDL_Color text_color = { R, G, B, A};
    int mWidth = 0;
    int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    double angle = 0.0;
    SDL_Point* center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont("pic/COMIC.TTF", font_size );

    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont,text, text_color );

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
    SDL_FreeSurface( textSurface );
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopyEx( renderer, mTexture, clip, &renderQuad, angle, center, flip );
    SDL_DestroyTexture( mTexture );
};
bool searchAC();

void firstmenu(SDL_Renderer *m_renderer)
{
    SDL_Texture *backgr;
    backgr=IMG_LoadTexture(m_renderer,"pic/backgr.jpg");
    SDL_Rect backgrrect= {0,0,W,H};
    SDL_Texture *backub;
    SDL_Texture *backsb;
    SDL_Texture *unextb;
    SDL_Texture *snextb;
    SDL_Texture *loginrect;
    SDL_Texture *registertexture;
    SDL_Texture *shoter;
    shoter=IMG_LoadTexture(m_renderer,"pic/shoter.png");
    SDL_Rect shoterr= {(W/2)-195,100,400,200};

    SDL_Rect loginb= {(W/2)-65,300,140,60};
    SDL_Texture *logins;
    logins=IMG_LoadTexture(m_renderer,"pic/logins.png");
    SDL_Texture *loginu;
    loginu=IMG_LoadTexture(m_renderer,"pic/loginu.png");

    SDL_Rect registerb= {(W/2)-65,380,140,60};
    SDL_Texture *registers;
    registers=IMG_LoadTexture(m_renderer,"pic/registers.png");
    SDL_Texture *registeru;
    registeru=IMG_LoadTexture(m_renderer,"pic/registeru.png");

    SDL_Event*e=new SDL_Event ();
    bool loginn=false,registerr=false,firstmenuu=true;
    while(firstmenuu==true)
    {
        SDL_PollEvent(e);
        SDL_RenderCopy(m_renderer,backgr,NULL,&backgrrect);
        SDL_RenderCopy(m_renderer,shoter,NULL,&shoterr);
        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>300)&&(e->motion.y<360))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                loginn=true;
            }
            else
            {
                loginn=false;
            }
            SDL_RenderCopy(m_renderer,logins,NULL,&loginb);
        }
        else
        {
            SDL_RenderCopy(m_renderer,loginu,NULL,&loginb);
        };

        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>380)&&(e->motion.y<440))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                registerr=true;
            }
            else
            {
                registerr=false;
            }
            SDL_RenderCopy(m_renderer,registers,NULL,&registerb);
        }
        else
        {
            SDL_RenderCopy(m_renderer,registeru,NULL,&registerb);
        }
        SDL_RenderPresent(m_renderer);


        /*
        SDL_DestroyTexture(logins);
        SDL_DestroyTexture(loginu);
        SDL_DestroyTexture(registers);
        SDL_DestroyTexture(registeru);
        SDL_DestroyTexture(backgr);
        */
        if(registerr==true)
        {
            firstmenuu=false;
            SDL_Rect usernrect= {500,280,250,55};
            SDL_Rect usernrect2= {500,440,250,55};

            SDL_Texture *registerrect;
            registerrect=IMG_LoadTexture(m_renderer,"pic/registerrect.png");

            SDL_Texture *registertexture;
            registertexture=IMG_LoadTexture(m_renderer,"pic/registerbackgr.jpg");
            SDL_RenderCopy(m_renderer,registertexture,NULL,&backgrrect);
            SDL_RenderCopy(m_renderer,registerrect,NULL,&usernrect);
            SDL_RenderCopy(m_renderer,registerrect,NULL,&usernrect2);

            SDL_Texture *snextb;
            snextb=IMG_LoadTexture(m_renderer,"pic/snext.png");
            SDL_Rect nextb= {442,630,140,60};
            SDL_Texture *unextb;
            unextb=IMG_LoadTexture(m_renderer,"pic/unext.png");

            SDL_RenderPresent(m_renderer);
            string textInput1 = "";
            string textInput2 = "";
            int n;
            bool nextt=false;
            int p=0,u=0;
            while((p==0)||(u==0)||(nextt==false))
            {
                if (SDL_PollEvent(e))
                {
                    if(e->button.button==SDL_BUTTON_LEFT)
                    {
                        if((e->motion.x>500)&&(e->motion.x<750)&&(e->motion.y>280)&&(e->motion.y<335))
                        {
                            n=285;
                        }
                        else if((e->motion.x>500)&&(e->motion.x<750)&&(e->motion.y>440)&&(e->motion.y<495))
                        {
                            n=445;
                        }
                        else
                        {
                            n=0;
                        }
                    }
                    if((e->motion.x>442)&&(e->motion.x<582)&&(e->motion.y>630)&&(e->motion.y<690))
                    {
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {
                            nextt=true;
                        }
                        else
                        {
                            nextt=false;
                        }
                        SDL_RenderCopy(m_renderer,snextb,NULL,&nextb);
                    }
                    else
                    {
                        SDL_RenderCopy(m_renderer,unextb,NULL,&nextb);
                    }
                    SDL_RenderPresent(m_renderer);

                    switch(e->type)
                    {
                    case SDL_TEXTINPUT:

                        if(n==445)
                        {
                            textInput1 += e->text.text;
                            cout<<textInput1<<'\n';
                            const char *C;
                            C = textInput1.c_str();
                            textman(m_renderer,510,n,C,25,0,0,0,255);
                            SDL_RenderPresent(m_renderer);
                            p=1;
                            break;
                        }

                        else if(n==285)
                        {
                            textInput2 += e->text.text;
                            cout<<textInput2<<'\n';
                            const char *C2;
                            C2 = textInput2.c_str();
                            textman(m_renderer,510,n,C2,25,0,0,0,255);
                            SDL_RenderPresent(m_renderer);
                            u=1;
                            break;
                        }


                    }//switch



                }//pollevent

            }//while register
            ifstream x("users.txt",ios::in);
            bool isFound=false;
            while(!x.eof())
            {
                string temp = "";
                getline(x,temp);
                for(int i=0; i<textInput2.size(); i++)
                {
                    if(temp[i]==textInput2[i])
                    {
                        isFound = true;
                    }
                    else
                    {
                        isFound =false;
                        break;
                    }
                }
            };
            if(isFound == false)
            {
                x.close();
                ofstream fout;  // Create Object of Ofstream
                ifstream fin;
                fin.open("users.txt");
                fout.open ("users.txt",ios::app); // Append mode
                if(fin.is_open())
                    fout<<textInput2<<" "<<textInput1<<endl;

                // // Writing data to file
                fin.close();
                fout.close();

            }
            else if(isFound == true)
            {
                firstmenuu=true;
            };

        }//if register

        if(loginn==true)
        {
            firstmenuu=false;
            SDL_Rect usernrect= {500,280,250,55};
            SDL_Rect usernrect2= {500,440,250,55};

            loginrect=IMG_LoadTexture(m_renderer,"pic/registerrect.png");

            registertexture=IMG_LoadTexture(m_renderer,"pic/registerbackgr.jpg");
            SDL_RenderCopy(m_renderer,registertexture,NULL,&backgrrect);
            SDL_RenderCopy(m_renderer,loginrect,NULL,&usernrect);
            SDL_RenderCopy(m_renderer,loginrect,NULL,&usernrect2);

            snextb=IMG_LoadTexture(m_renderer,"pic/snext.png");
            SDL_Rect nextb= {442,630,140,60};
            unextb=IMG_LoadTexture(m_renderer,"pic/unext.png");

            backsb=IMG_LoadTexture(m_renderer,"pic/backs.png");
            SDL_Rect backb= {722,630,140,60};
            backub=IMG_LoadTexture(m_renderer,"pic/backu.png");
            SDL_RenderPresent(m_renderer);
            string textInput1 = "";
            string textInput2 = "";
            int n;
            bool nextt=false;
            int p=0,u=0;
            bool backk=false;
            while((p==0)||(u==0)||(nextt==false))
            {
                if (SDL_PollEvent(e))
                {
                    if(e->button.button==SDL_BUTTON_LEFT)
                    {
                        if((e->motion.x>500)&&(e->motion.x<750)&&(e->motion.y>280)&&(e->motion.y<335))
                        {
                            n=285;
                        }
                        else if((e->motion.x>500)&&(e->motion.x<750)&&(e->motion.y>440)&&(e->motion.y<495))
                        {
                            n=445;
                        }
                        else
                        {
                            n=0;
                        }
                    }

                    if((e->motion.x>442)&&(e->motion.x<582)&&(e->motion.y>630)&&(e->motion.y<690))
                    {
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {
                            nextt=false;
                        }
                        else
                        {
                            nextt=false;
                        }
                        SDL_RenderCopy(m_renderer,snextb,NULL,&nextb);
                    }
                    else
                    {
                        SDL_RenderCopy(m_renderer,unextb,NULL,&nextb);
                    }

                    if((e->motion.x>722)&&(e->motion.x<862)&&(e->motion.y>630)&&(e->motion.y<690))
                    {
                        if(e->button.button==SDL_BUTTON_LEFT)
                        {
                            backk=true;
                        }
                        else
                        {
                            backk=false;
                        }
                        SDL_RenderCopy(m_renderer,backsb,NULL,&backb);
                    }
                    else
                    {
                        SDL_RenderCopy(m_renderer,backub,NULL,&backb);
                    }


                    SDL_RenderPresent(m_renderer);

                    switch(e->type)
                    {
                    case SDL_TEXTINPUT:

                        if(n==445)
                        {
                            textInput1 += e->text.text;
                            cout<<textInput1<<'\n';
                            const char *C;
                            C = textInput1.c_str();
                            textman(m_renderer,510,n,C,25,0,0,0,255);
                            SDL_RenderPresent(m_renderer);
                            p=1;
                            break;
                        }

                        else if(n==285)
                        {
                            textInput2 += e->text.text;
                            cout<<textInput2<<'\n';
                            const char *C2;
                            C2 = textInput2.c_str();
                            textman(m_renderer,510,n,C2,25,0,0,0,255);
                            SDL_RenderPresent(m_renderer);
                            u=1;
                            break;
                        }


                    }//switch



                }//pollevent


                if(backk==true)
                {
                    loginn=false;
                    firstmenuu=true;
                    break;
                }


            }//while login

        }//if login

    }

    SDL_DestroyTexture(backgr);
    SDL_DestroyTexture(shoter);
    SDL_DestroyTexture(logins);
    SDL_DestroyTexture(loginu);
    SDL_DestroyTexture(registers);
    SDL_DestroyTexture(registeru);
    SDL_DestroyTexture(backub);
    SDL_DestroyTexture(backsb);
    SDL_DestroyTexture(unextb);
    SDL_DestroyTexture(snextb);
    SDL_DestroyTexture(registertexture);
    SDL_DestroyTexture(loginrect);
    SDL_DestroyTexture(unextb);
    SDL_DestroyTexture(snextb);
    SDL_DestroyTexture(registertexture);

}//while firstmenu

void secmenu(SDL_Renderer *m_renderer,SDL_Window *m_window)
{


    SDL_Rect startb= {(W/2)-65,300,140,60};
    SDL_Texture *starts;
    starts=IMG_LoadTexture(m_renderer,"pic/starts.png");
    SDL_Texture *startu;
    startu=IMG_LoadTexture(m_renderer,"pic/startu.png");

    SDL_Rect soundb= {(W/2)-65,380,140,60};
    SDL_Texture *sounds;
    sounds=IMG_LoadTexture(m_renderer,"pic/sounds.png");
    SDL_Texture *soundu;
    soundu=IMG_LoadTexture(m_renderer,"pic/soundu.png");

    SDL_Rect exitb= {(W/2)-65,620,140,60};
    SDL_Texture *exits;
    exits=IMG_LoadTexture(m_renderer,"pic/exits.png");
    SDL_Texture *exitu;
    exitu=IMG_LoadTexture(m_renderer,"pic/exitu.png");

    SDL_Rect helpb= {(W/2)-65,540,140,60};
    SDL_Texture *helps;
    helps=IMG_LoadTexture(m_renderer,"pic/helps.png");
    SDL_Texture *helpu;
    helpu=IMG_LoadTexture(m_renderer,"pic/helpu.png");

    SDL_Rect musicb= {(W/2)-65,460,140,60};
    SDL_Texture *musics;
    musics=IMG_LoadTexture(m_renderer,"pic/musics.png");
    SDL_Texture *musicu;
    musicu=IMG_LoadTexture(m_renderer,"pic/musicu.png");

    SDL_Texture *backgr;
    backgr=IMG_LoadTexture(m_renderer,"pic/backgr.jpg");
    SDL_Rect backgrrect= {0,0,W,H};

    SDL_Texture *shoter;
    shoter=IMG_LoadTexture(m_renderer,"pic/shoter.png");
    SDL_Rect shoterr= {(W/2)-195,100,400,200};

    bool startt=false,soundd=false,musicc=false,helpp=false,exitt=false,secmenubool=true;
    SDL_Event*e=new SDL_Event ();
    while(secmenubool==true)
    {
        SDL_PollEvent(e);


        SDL_RenderCopy(m_renderer,backgr,NULL,&backgrrect);
        SDL_RenderCopy(m_renderer,shoter,NULL,&shoterr);
        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>300)&&(e->motion.y<360))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                startt=true;
            }
            else
            {
                startt=false;
            }
            SDL_RenderCopy(m_renderer,starts,NULL,&startb);
        }
        else
        {
            SDL_RenderCopy(m_renderer,startu,NULL,&startb);
        };
        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>460)&&(e->motion.y<520))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                musicc=true;
            }
            else
            {
                musicc=false;
            }
            SDL_RenderCopy(m_renderer,musics,NULL,&musicb);
            ;
        }
        else
        {
            SDL_RenderCopy(m_renderer,musicu,NULL,&musicb);
            ;
        };

        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>540)&&(e->motion.y<600))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                helpp=true;
            }
            else
            {
                helpp=false;
            }
            SDL_RenderCopy(m_renderer,helps,NULL,&helpb);
            ;
        }
        else
        {
            SDL_RenderCopy(m_renderer,helpu,NULL,&helpb);
            ;
        };
        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>380)&&(e->motion.y<440))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                soundd=true;
            }
            else
            {
                soundd=false;
            }
            SDL_RenderCopy(m_renderer,sounds,NULL,&soundb);
            ;
        }
        else
        {
            SDL_RenderCopy(m_renderer,soundu,NULL,&soundb);
            ;
        };
        if((e->motion.x>(W/2)-65)&&(e->motion.x<(W/2)-65+140)&&(e->motion.y>620)&&(e->motion.y<680))
        {
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                exitt=true;
            }
            else
            {
                exitt=false;
            }
            SDL_RenderCopy(m_renderer,exits,NULL,&exitb)
            ;
        }
        else
        {
            SDL_RenderCopy(m_renderer,exitu,NULL,&exitb);
            ;
        };


        SDL_RenderPresent( m_renderer );
        if(helpp==true)
        {
            bool backk=false;
            SDL_Texture *helptexture;
            helptexture=IMG_LoadTexture(m_renderer,"pic/backgrhelp.jpg");
            SDL_Texture *backtextures;
            backtextures=IMG_LoadTexture(m_renderer,"pic/backs.png");
            SDL_Texture *backtextureu;
            backtextureu=IMG_LoadTexture(m_renderer,"pic/backu.png");
            SDL_Rect backrect= {440,630,140,60};
            while(backk==false)
            {

                SDL_RenderCopy(m_renderer,helptexture,NULL,&backgrrect);
                if((e->motion.x>440)&&(e->motion.x<580)&&(e->motion.y>630)&&(e->motion.y<690))
                {
                    SDL_RenderCopy(m_renderer,backtextures,NULL,&backrect);
                    if(e->button.button==SDL_BUTTON_LEFT)
                    {
                        backk=true;
                    }
                    else
                    {
                        backk=false;
                    }
                }
                else
                {
                    SDL_RenderCopy(m_renderer,backtextureu,NULL,&backrect);
                }


                SDL_PollEvent(e);
                SDL_RenderPresent( m_renderer );
            }
            helpp=false;
            SDL_DestroyTexture(helptexture);
            SDL_DestroyTexture(backtextures);
            SDL_DestroyTexture(backtextureu);

        }
        if(startt==true)
        {
            secmenubool=false;
            SDL_DestroyTexture(backgr);
            SDL_DestroyTexture(shoter);
            SDL_DestroyTexture(startu);
            SDL_DestroyTexture(starts);
            SDL_DestroyTexture(musicu);
            SDL_DestroyTexture(musics);
            SDL_DestroyTexture(soundu);
            SDL_DestroyTexture(sounds);
            SDL_DestroyTexture(helpu);
            SDL_DestroyTexture(helps);
            SDL_DestroyTexture(exits);
            SDL_DestroyTexture(exitu);
        }

        if(soundd==true)
        {



        }

        if(musicc==true)
        {




        }

        if(exitt==true)
        {
            SDL_DestroyTexture(backgr);
            SDL_DestroyTexture(shoter);
            SDL_DestroyTexture(startu);
            SDL_DestroyTexture(starts);
            SDL_DestroyTexture(musicu);
            SDL_DestroyTexture(musics);
            SDL_DestroyTexture(soundu);
            SDL_DestroyTexture(sounds);
            SDL_DestroyTexture(helpu);
            SDL_DestroyTexture(helps);
            SDL_DestroyTexture(exits);
            SDL_DestroyTexture(exitu);
            SDL_DestroyWindow( m_window );
            SDL_DestroyRenderer( m_renderer );
            IMG_Quit();
            SDL_Quit();

        }

    }

}
struct Point
{
    double x,y;
    void to(double to_x, double to_y)
    {
        x = to_x;
        y = to_y;
    }
};

int  mapmenu(SDL_Renderer *m_renderer)
{
    SDL_Texture *n1;
    n1=IMG_LoadTexture(m_renderer,"pic/sirk2.png");
    SDL_Rect r1= {150,50,200,130};
    SDL_Texture *n2;
    n2=IMG_LoadTexture(m_renderer,"pic/sirk3.jpg");
    SDL_Rect r2= {350,200,200,130};
    SDL_Texture *n3;
    n3=IMG_LoadTexture(m_renderer,"pic/sirk4.jpg");
    SDL_Rect r3= {750,350,200,130};
    SDL_Texture *n4;
    n4=IMG_LoadTexture(m_renderer,"pic/sirk5.jpg");
    SDL_Rect r4= {550,500,200,130};
    SDL_Texture *n5;
    n5=IMG_LoadTexture(m_renderer,"pic/backgr.jpg");
    SDL_Rect r5= {0,0,1280,800};
    SDL_Event *e = new SDL_Event();
    e->button.button=0;
    bool f=true;
    int ziba;
    while(f==true)
    {
        SDL_PollEvent(e);
        SDL_RenderCopy(m_renderer,n5,NULL,&r5);
        SDL_RenderCopy(m_renderer,n1,NULL,&r1);
        SDL_RenderCopy(m_renderer,n2,NULL,&r2);
        SDL_RenderCopy(m_renderer,n3,NULL,&r3);
        SDL_RenderCopy(m_renderer,n4,NULL,&r4);
        if(e->button.button==SDL_BUTTON_LEFT)
        {
            if((e->motion.x>150)&&(e->motion.x<350)&&(e->motion.y>50)&&(e->motion.y<180))
            {
                ziba=1;
                f=false;
            };
            if((e->motion.x>350)&&(e->motion.x<550)&&(e->motion.y>200)&&(e->motion.y<330))
            {
                ziba=2;
                f=false;
            };
            if((e->motion.x>750)&&(e->motion.x<950)&&(e->motion.y>350)&&(e->motion.y<480))
            {
                ziba=3;
                f=false;
            };
            if((e->motion.x>550)&&(e->motion.x<750)&&(e->motion.y>500)&&(e->motion.y<630))
            {
                ziba=4;
                f=false;
            };
        }
        SDL_RenderPresent(m_renderer);
    }
    SDL_DestroyTexture(n1);
    SDL_DestroyTexture(n2);
    SDL_DestroyTexture(n3);
    SDL_DestroyTexture(n4);
    SDL_DestroyTexture(n5);
    return ziba;
}

int mapshape(SDL_Renderer *m_renderer)
{
    SDL_Texture *n1;
    n1=IMG_LoadTexture(m_renderer,"pic/map1.png");
    SDL_Rect r1= {300,50,200,130};
    SDL_Texture *n2;
    n2=IMG_LoadTexture(m_renderer,"pic/map2.png");
    SDL_Rect r2= {500,50,200,130};
    SDL_Texture *n3;
    n3=IMG_LoadTexture(m_renderer,"pic/map3.png");
    SDL_Rect r3= {700,50,200,130};
    SDL_Texture *n5;
    n5=IMG_LoadTexture(m_renderer,"pic/backgr.jpg");
    SDL_Rect r5= {0,0,1280,800};
    int zibasabz;
    bool f=true;
    SDL_Event *e = new SDL_Event();
    while(f==true)
    {
        SDL_PollEvent(e);
        SDL_RenderCopy(m_renderer,n5,NULL,&r5);
        SDL_RenderCopy(m_renderer,n1,NULL,&r1);
        SDL_RenderCopy(m_renderer,n2,NULL,&r2);
        SDL_RenderCopy(m_renderer,n3,NULL,&r3);

        if(e->button.button==SDL_BUTTON_LEFT)
        {
            if((e->motion.x>300)&&(e->motion.x<500)&&(e->motion.y>50)&&(e->motion.y<180))
            {
                zibasabz=1;
                f=false;
            };
            if((e->motion.x>500)&&(e->motion.x<700)&&(e->motion.y>50)&&(e->motion.y<180))
            {
                zibasabz=2;
                f=false;
            };
            if((e->motion.x>700)&&(e->motion.x<900)&&(e->motion.y>50)&&(e->motion.y<180))
            {
                zibasabz=3;
                f=false;
            };

        }
        SDL_RenderPresent(m_renderer);
    }
    SDL_DestroyTexture(n1);
    SDL_DestroyTexture(n2);
    SDL_DestroyTexture(n3);
    SDL_DestroyTexture(n5);
    return zibasabz;
}

Point *curve(int mapnum)
{


    int   xmax=0, xmin=0, ymax=0, ymin=0;

    Point *points=new Point[200];
    points[0].to(0, 0);
    double d2t,dt,t;
    int z;
    if(mapnum==1)
    {
        d2t=0.000522048;
        dt=-0.0041305;
        t=0.0033008;
        z=50;
    }
    else if(mapnum==2)
    {
        d2t=0.000806275;
        dt=-0.0231334;
        t=-0.476771;
        z=150;
    }
    else if(mapnum==3)
    {
        d2t=-0.00026859;
        dt=-0.00907472;
        t=0.643117;
        z=100;
    };

    // double d2t=0.000806275,dt=-0.02831334,t=-0.476771;int z=150;//map2

    double x, y;
    for (int i = 1; i <200; i++)
    {
        x = points[i-1].x + (cos(t)*0.08);
        y = points[i-1].y + (sin(t)*0.08);

        points[i].to(x,y);
        if (points[i].x > xmax)
            xmax = points[i].x;
        if (points[i].x < xmin)
            xmin = points[i].x;
        if (points[i].y > ymax)
            ymax = points[i].y;
        if (points[i].y < ymin)
            ymin = points[i].y;

        dt += d2t;
        t += dt;
    }

    for (int i = 0; i < 200; i++)
    {
        points[i].x = (points[i].x - xmin)*1280/(xmax*1.3- xmin*1.4);
        points[i].x+= 50;
        points[i].y = (points[i].y - ymin)*800/(ymax*1.3 - ymin*1.4);
        points[i].y += z;

    };

    return points;
};


void bazi(SDL_Renderer *m_renderer,int zibasabz,int mapnum)
{


    SDL_Event *e = new SDL_Event();


    Point *curvepoints;
    curvepoints=curve(zibasabz);

    struct balls
    {
        double x=50,y=50;
        int n=0;
        int o,R,G,B;
        balls()
        {

            o=rand()%4;
            if(o==0)
            {
                R=255;
                G=0;
                B=255;
            }
            else if(o==1)
            {
                R=0;
                G=0;
                B=255;
            }
            else if(o==2)
            {
                R=255;
                G=255;
                B=0;
            }
            else if(o==3)
            {
                R=255;
                G=0;
                B=0;
            };


        }
    };

    struct cannonballs
    {
        double x=765,y=530;
        int n=0;

        int o,R,G,B;
        cannonballs()
        {

            o=rand()%7;
            if(o==0)
            {
                R=255;
                G=0;
                B=255;
            }
            else if(o==1)
            {
                R=0;
                G=0;
                B=255;
            }
            else if(o==2)
            {
                R=255;
                G=255;
                B=0;
            }
            else if(o==3)
            {
                R=255;
                G=0;
                B=0;
            }
            else if(o==4)
            {
                R=255;    // Fireball power-up
                G=105;
                B=0;
            }
            else if(o==5)
            {
                R=0;    // Bomb AoE power-up
                G=255;
                B=255;
            }
            else if(o==6)
            {
                R=255;
                B=255;
                G=255;
            };// Wildcard color-clear power-up
        }
    };
    SDL_Rect bg= {0,0,1280,800};
    SDL_Texture *mtexture;
    if(mapnum==1)
    {
        mtexture=IMG_LoadTexture(m_renderer,"pic/sirk2.png");
    };
    if(mapnum==2)
    {
        mtexture=IMG_LoadTexture(m_renderer,"pic/sirk3.jpg");
    };
    if(mapnum==3)
    {
        mtexture=IMG_LoadTexture(m_renderer,"pic/sirk4.jpg");
    };
    if(mapnum==4)
    {
        mtexture=IMG_LoadTexture(m_renderer,"pic/sirk5.jpg");
    };
    SDL_RenderCopy(m_renderer,mtexture,NULL,&bg);
    SDL_RenderPresent(m_renderer);
    bool lost=false;
    int qq,qqq;
    if(zibasabz==1)
    {
        qq=640;
        qqq=420;
    }
    if(zibasabz==2)
    {
        qq=490;
        qqq=320;
    }
    if(zibasabz==3)
    {
        qq=640;
        qqq=120;
    }


    SDL_Rect bg1= {qq,qqq,250,200};
    SDL_Texture *mtexture1;
    mtexture1=IMG_LoadTexture(m_renderer,"pic/clown_shooter.png");
    SDL_RenderCopy(m_renderer,mtexture1,NULL,&bg1);
    SDL_RenderPresent(m_renderer);

    for(int i=0; i<200; i++) // Render track path
    {
        filledEllipseRGBA(m_renderer,curvepoints[i].x,curvepoints[i].y,20,20,0,0,0,255)   ;
        SDL_RenderPresent( m_renderer );
    }


    balls toop_m[10000];
    int toop_mnums=0;
    cannonballs dahan[300];
    int dahannum=0;
    for(int i=0; i<300; i++)
    {
        cannonballs x;
        dahan[i]=x;
        if(zibasabz==2)
        {
            dahan[i].x=490+125;
            dahan[i].y=430;
        }
        else if(zibasabz==3)
        {
            dahan[i].x=640+125;
            dahan[i].y=120+110;
        };

    }
    int m=0;
    int f=0;
    int n=200;// Difficulty / spawn interval
    int nums=0;// Score
    int w=0;
    bool partab=false;
    int t=0;
    bool isAiming=false;
    int nn=10,nn1=10;
    char const* C,*C1;
    int mm=0;
    while(lost==false)
    {
        f++;
        SDL_PollEvent(e);
        if(e->key.keysym.sym==SDLK_SPACE)
        {

            dahannum++;
            e->key.keysym.sym=0;
        }

//filledEllipseRGBA(m_renderer,y.x,y.y,10,10,y.R,y.G,y.B,255);

//aalineRGBA(m_renderer,765,530,e->motion.x,e->motion.y,dahan[dahannum].R,dahan[dahannum].G,dahan[dahannum].B,255);
        string s =to_string(nn);
        C = s.c_str();
        string s1 =to_string(nn1);
        C1 = s1.c_str();
        filledEllipseRGBA(m_renderer,80,100,20,20,255,165,0,255) ;
        filledEllipseRGBA(m_renderer,80,150,20,20,0,255,255,255) ;
        filledEllipseRGBA(m_renderer,80,200,20,20,255,255,255,255) ;

// textman(m_renderer,110,100,C,30,255,255,255,255);
// textman(m_renderer,110,150,C1,30,255,255,255,255);
        if(f%n==0)
        {
            balls b;

            toop_m[toop_mnums]=b;
            toop_mnums++;

            SDL_RenderCopy(m_renderer,mtexture,NULL,&bg);
            SDL_RenderCopy(m_renderer,mtexture1,NULL,&bg1);
            for(int i=0; i<200; i++) // Render track path
            {
                filledEllipseRGBA(m_renderer,curvepoints[i].x,curvepoints[i].y,20,20,0,0,0,255)   ;
                ;
            }

            for(int i=0; i<=toop_mnums; i+=3)
            {
                balls b;
                b=toop_m[i];
                if(i>=3)
                {
                    toop_m[i].R=toop_m[i-3].R;
                    toop_m[i-3].G=toop_m[i-3].G;
                    toop_m[i-3].B=toop_m[i-3].B;
                }


                b.x=curvepoints[toop_m[i].n].x;
                b.y=curvepoints[toop_m[i].n].y;
                filledEllipseRGBA(m_renderer,b.x,b.y,20,20,b.R,b.G,b.B,255);
                toop_m[i]=b;
                if(toop_m[i].n<205)
                {
                    toop_m[i].n++;
                };

                if((dahan[dahannum].y<b.y+20)&&(dahan[dahannum].y>b.y-20)&&(dahan[dahannum].x<b.x+20)&&(dahan[dahannum].x>b.x-20))
                {
                    //toop_m[i].n+=3;

                    if(dahan[dahannum].o==4)
                    {
                        mm++;
                        toop_m[i].o=13;
                        nn--;
                    }
                    if(dahan[dahannum].o==5)
                    {
                        mm++;
                        toop_m[i].o=13;
                        toop_m[i+1].o=13;
                        toop_m[i-1].o=13;
                        toop_m[i-2].o=13;
                        toop_m[i+2].o=13;
                        nn1--;
                    };
                    if(dahan[dahannum].o==6)
                    {
                        for(int j=0; j<=toop_mnums; j+=3)
                        {
                            if(toop_m[i].o==toop_m[j].o)
                            {
                                toop_m[i].o=13;
                                mm++;
                            }
                        }
                    }
                    if(dahan[dahannum].o==b.o)
                    {
                        int c=i;
                        for(int j=i; c<=i+15; c+=3 )
                        {
                            if(b.o==toop_m[c].o)
                            {
                                mm++;
                                toop_m[c].o=13;
                            }
                            else
                            {
                                break;
                            }

                        }
                        c=i;
                        for(int j=i; c<=i+15; c-=3 )
                        {
                            if(b.o==toop_m[c].o)
                            {
                                mm++;
                                toop_m[c].o=13;
                            }
                            else
                            {
                                break;
                            }

                        }

                    }
                    for(int i=0; i<=toop_mnums; i+=3)
                    {
                        if(toop_m[i].o==13)
                        {
                            toop_m[i].R=0;
                            toop_m[i].G=0;
                            toop_m[i].B=0;
                        }
                    }
                    for(int j=0; j<=i; j+=3)
                    {
                        toop_m[j].n-=(mm*3);
                        // if(mm!=0){toop_m[j].n-=6;}

                    }

                    dahannum++;
                    partab=false;
                };

            };
            int dx,dy;
            if(isAiming==true)
            {
                dx=765-e->motion.x,dy=530-e->motion.y;
                isAiming=false;
            }
            if(partab==true)
            {
                dahan[dahannum].x-=dx/14;
                dahan[dahannum].y-=dy/14;
                t++;



                if(t==40)
                {
                    partab=false;
                    dahannum++;
                    t=0;
                }
            }
            filledEllipseRGBA(m_renderer,dahan[dahannum].x,dahan[dahannum].y,20,20,dahan[dahannum].R,dahan[dahannum].G,dahan[dahannum].B,255);
            if(e->button.button==SDL_BUTTON_LEFT)
            {
                partab=true;
                isAiming=true;
                e->button.button=0;

            }
        }

        SDL_RenderPresent(m_renderer);
    }

    //Finalize and free resources
// SDL_DestroyWindow( m_window );
    //  SDL_DestroyRenderer( m_renderer );
    // IMG_Quit();
    // SDL_Quit();

}

int main( int argc, char * argv[] )
{
    srand(time(NULL));

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
                
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1280, 800, WND_flags, &m_window, &m_renderer );
    SDL_SetWindowTitle(m_window, "Jungle Marble Blast");
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );

    firstmenu(m_renderer);
    secmenu(m_renderer,m_window);
    int ziba=mapmenu(m_renderer);
    int zibasabz=mapshape(m_renderer);
    bazi(m_renderer,zibasabz,ziba);


}

#include <stdio.h>
#include <stdbool.h>

struct proc
{
    int ar_time,bust,leave_time,time_left,attend_time,rudiment,exec;
};

struct proc pain[10];
int front=0,rear=0;

void add(struct proc lal, int ind)
{
    pain[front]=lal;
    pain[front].rudiment=ind;

    front++;
}

int extract()
{
    int min=1000,minin;
    for(int i=0;i<front;i++)
    {

        if(pain[i].time_left<min)
        {

            min=pain[i].time_left;
            minin=i;
        }
    }
    rear++;

    pain[minin].time_left=1500;

    return pain[minin].rudiment;
}

void nonp()
{
    int numbah,counter=0,a1=0,a2=0;
    printf("How many processes? ");

    scanf("%d",&numbah);
    int pp[numbah];
    printf("Enter the burst time for each process\n");
    for (int i=0;i<numbah;i++)
        scanf("%d",&pp[i]);
    printf("Waiting time\t");
    printf("Turnaround time\n");
    for (int i=0;i<numbah;i++)
    {
        printf("%d\t\t",counter);
        printf("%d\n",counter+pp[i]);
        a1=a1+counter;
        a2=a2+counter+pp[i];
        counter=counter+pp[i];
    }
    printf("Avg Waiting time %f\nAvg Turnaround time %f",a1/(float)numbah,a2/(float)numbah);
}



void prem()
{
    int numbah,global_cock=0,pres=0,cunt=0,a1=0,a2=0,a3=0;
    printf("How many processes? ");
    scanf("%d",&numbah);
    struct proc hehe[numbah];
    printf("Enter arrival time followed by the burst time for each process\n");
    for(int i=0;i<numbah;i++)
    {
        pain[i].time_left=0;
    }
    for (int i=0;i<numbah;i++)
    {
        scanf("%d",&hehe[i].ar_time);
        scanf("%d",&hehe[i].bust);
        hehe[i].time_left=hehe[i].bust;
    }
    hehe[0].exec=1;
    hehe[0].attend_time=0;
    for (int i=1;i<numbah;i++)
    {
        global_cock=hehe[i].ar_time;
        hehe[pres].time_left=hehe[pres].bust-global_cock+hehe[pres].ar_time;
        if(hehe[pres].time_left<=0)
        {
            cunt++;
            hehe[pres].leave_time=hehe[pres].ar_time+hehe[pres].bust;
            int pp=hehe[pres].leave_time;
            if(global_cock!=hehe[pres].leave_time)
            {
                int timer=hehe[pres].leave_time;
                int timeleft=global_cock-hehe[pres].leave_time;
                pp=pp+timeleft;
                while(timeleft>0 && (front>rear))
                {
                    int sada=extract();
                    if(hehe[sada].time_left>timeleft)
                    {
                        hehe[sada].time_left=hehe[sada].time_left-timeleft;
                        add(hehe[sada],sada);
                        timeleft=0;
                        if(hehe[sada].exec!=1)
                        {
                            hehe[sada].attend_time=timer;
                            hehe[sada].exec=1;
                        }
                    }
                    else
                    {
                        hehe[sada].leave_time=timer+hehe[sada].time_left;
                        if(hehe[sada].exec!=1)
                        {
                            hehe[sada].attend_time=timer;
                            hehe[sada].exec=1;
                        }
                        timer=timer+hehe[sada].time_left;
                        timeleft=timeleft-hehe[sada].time_left;
                        cunt++;
                    }
                }
            }
            add(hehe[i],i);
            pres=extract();
            if(hehe[pres].exec!=1)
            {
                hehe[pres].attend_time=pp;
                hehe[pres].exec=1;
            }
        }
        else if(hehe[i].bust<hehe[pres].time_left)
        {
            add(hehe[pres],pres);
            pres=i;
            if(hehe[pres].exec!=1)
            {
                hehe[pres].attend_time=global_cock;
                hehe[pres].exec=1;
            }
        }
        else
        {
            add(hehe[i],i);
        }
    }
    hehe[pres].leave_time=global_cock+hehe[pres].time_left;
    global_cock=hehe[pres].leave_time;
    cunt++;
    int temp=hehe[pres].leave_time;
    while(cunt<=numbah-1)
    {
        pres=extract();
        if(hehe[pres].exec!=1)
        {
            hehe[pres].attend_time=temp;
            hehe[pres].exec=1;
        }
        hehe[pres].leave_time=global_cock+hehe[pres].time_left;
        temp=hehe[pres].leave_time;
        global_cock=hehe[pres].leave_time;
        cunt++;
    }
    printf("Waiting time\t");
    printf("Response time\t");
    printf("Turnaround time\n");
    for (int i=0;i<numbah;i++)
    {
        printf("%d\t\t",hehe[i].leave_time-hehe[i].ar_time-hehe[i].bust);
        printf("%d\t\t",hehe[i].attend_time-hehe[i].ar_time);
        printf("%d\n",hehe[i].leave_time-hehe[i].ar_time);
        a1=a1+hehe[i].leave_time-hehe[i].ar_time-hehe[i].bust;
        a2=a2+hehe[i].attend_time-hehe[i].ar_time;
        a3=a3+hehe[i].leave_time-hehe[i].ar_time;
    }
    printf("Avg Waiting time %f\nAvg Response time %f\nAvg Turnaround time %f",a1/(float)numbah,a2/(float)numbah,a3/(float)numbah);
}

void main()
{
    printf("Enter 1 for premtive or 0 for non premptive ");
    int dec;
    scanf("%d",&dec);
    if(dec==1)
        prem();
    else
        nonp();
}
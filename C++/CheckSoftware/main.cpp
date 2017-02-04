#include <iostream>
#include <string>
#include <map>
#include <set>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define SEPARATE_SIGN " "

using namespace std;

map<string, set<string> > software;

int getSoftware(FILE* fp) {
    if (NULL == fp) {
        return -1;
    }
    char line[1024];
    char* str = NULL;
    int lno = 1;
    while (!feof(fp)) {
        fgets(line, 1024, fp);
        //cout << lno++ << " " << line << endl;
        str = strtok(line, SEPARATE_SIGN);
        while (NULL != str) {
            //cout << str << endl;
            if (strcmp(str, "PNLCODE") != 0) {
                break; 
            } 
            str = strtok(NULL, SEPARATE_SIGN); // =
            str = strtok(NULL, SEPARATE_SIGN); // panel software
            if (NULL == str) {
                break;
            }
            string panelSoftware(str);
            // main software
            fgets(line, 1024, fp);
            //fscanf(fp, "%[^\n]", line);
            str = strtok(line, SEPARATE_SIGN);
            if (NULL == str || strcmp(str, "SYSCODE") != 0) {
                break;
            }

            str = strtok(NULL, SEPARATE_SIGN); // =
            str = strtok(NULL, SEPARATE_SIGN); // main software
            if (NULL == str) {
                break;
            }
            string mainSoftware(str);
            software[mainSoftware].insert(panelSoftware); 
        }
    }
    cout << "------file end---------" << endl;
    fclose(fp);
    
}

set<string> checkSoftware; 

void getCheckSoftWare(FILE* fp) {
    char line[1024];
    while (!feof(fp)) {
        //fscanf(fp, "%[^\n]", line);
        fgets(line, 1024, fp);
        char* str = strtok(line, SEPARATE_SIGN);
        if (str == NULL) {
            break;
        }
        string panelSoftware(str);
        checkSoftware.insert(panelSoftware);
    }
}
int list_dir_name(char* dirname){
    DIR* dp;
    struct dirent* dirp;
    struct stat st;
    /* open dirent directory */
    if((dp = opendir(dirname))==NULL)
    {
        cout << "opendir" << endl;
        return -1;
    }
    while((dirp=readdir(dp))!=NULL)
    {
        char fullname[255];
       memset(fullname,0,sizeof(fullname));
        /* ignore hidden files */
        if(dirp->d_name[0]=='.')
            continue;
        strncpy(fullname,dirname,sizeof(fullname));
        strncat(fullname,"/",sizeof(fullname));
        strncat(fullname,dirp->d_name,sizeof(fullname));
        cout << fullname << endl;
        /* get dirent status */
        if(stat(fullname,&st)==-1)
        {
            return -1;
        }
        if (!S_ISDIR(st.st_mode)) {
            getSoftware(fopen(fullname, "rt"));
        }
        /* if dirent is a directory, call itself */
        if(S_ISDIR(st.st_mode)&&list_dir_name(fullname)==-1)
            return -1;
    }
    return 0;
}

int main() {
    char path[1024];
    getcwd(path, 1024);
    cout << "path is " << path << endl;
    list_dir_name(path);
    map<string, set<string> >::iterator begin = software.begin();
    while (begin != software.end()) {
        set<string> panel = begin->second;
        string main = begin->first;
        cout << endl;
        cout << "-----------------------------------------" << endl;
        cout << "main software : " << main << endl;
        set<string>::iterator it = panel.begin();
        while (it != panel.end()) {
            cout << "  " << *it;
            it++;
        }
        begin++;
    } 
}

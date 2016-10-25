#!/bin/sh

git filter-branch --commit-filter '
    if [ "$GIT_COMMITTER_NAME" = "Xenofon Vassilakopoulos" ];
    then
            GIT_COMMITTER_NAME="xvass";
            GIT_AUTHOR_NAME="xvass";
            GIT_COMMITTER_EMAIL="xenofonv@gmail.com";
            GIT_AUTHOR_EMAIL="xenofonv@gmail.com";
            git commit-tree "$@";
    else
            git commit-tree "$@";
    fi' HEAD

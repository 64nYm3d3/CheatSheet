 # How to download a git repo

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git clone [url] [file location]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ex..
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git clone https://github.com/secretsqirrel/the-back-door-factory /extras/opt/the-backdoor-factory
git clone https://github.com/fuzzdb-project/fuzzdb /extras/web-apps/fuzzdb
(While in the FuzzDB dir, you can update your local repo with the command "git pull")
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                                
#  Create a new repository

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
echo "# CheatSheet" >> README.md                             #creates local .md file, placing "# CheatSheet" in it
git init                                                     #initialize local repo
git add README.md                                            #adds readme to git repo
git commit -m "first commit"

git remote add origin https://github.com/64nYm3d3/CheatSheet.git
git push -u origin master
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#   Push the repo
                       
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                      
git remote add origin [https://github.com/64nYm3d3/CheatSheet.git]
git push -u origin master
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#    Git Pull

From what I understand, git pull will pull down from a remote  whatever you ask (so, whatever trunk you’re asking for) and instantly  merge it into the branch you’re in when you make the request. Pull is a  high-level request that runs ‘fetch’ then a ‘merge’ by default, or a  rebase with ‘–rebase’. You could do without it, it’s just a convenience.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git checkout localBranch
git pull origin master
git branch
master
* localBranch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


The above will merge the remote “master” branch into the local “localBranch”.


# Git fetch

Fetch is similar to pull, except it won’t do any merging.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git checkout localBranch
git fetch origin remoteBranch
git branch
master
 * localBranch
remoteBranch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

So, the fetch will have pulled down the remoteBranch and put it into a local branch called “remoteBranch”.  creates a local copy of a remote branch which you shouldn’t manipulate  directly; instead create a proper local branch and work on that. ‘git  checkout’ has a confusing feature though. If you ‘checkout’ a local copy  of a remote branch, it creates a local copy and sets up a merge to it  by default.

# Git Add

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git add file_path
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Git clone

git clone [url] [file location]
                           
 
Git clone will clone a repo int a newly created directory. It’s useful for when you’re setting up your local doodah


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cd newfolder
git clone git@github.com:whatever/something.git
git branch
 * master
remoteBranch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


 (While in the FuzzDB dir, you can update your local repo with the command "git pull")
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
git clone https://github.com/secretsqirrel/the-back-door-factory /extras/opt/the-backdoor-factory
git clone https://github.com/fuzzdb-project/fuzzdb /extras/web-apps/fuzzdb
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Git clone additionally creates a remote called ‘origin’ for the repo  cloned from, sets up a local branch based on the remote’s active branch  (generally master), and creates remote-tracking branches for all the  branches in the repo

# Git rebase

Finally, git rebase is pretty cool. Anything you’ve changed by  committing to your current branch but are no in the upstream are saved  to a temporary area, so your branch is the same as it was before you  started your changes, IE, clean. It then grabs the latest version of the branch from the remote If  you do ‘git pull –rebase’, git will pull down the remote changes,  rewind your local branch, then replays all your changes over the top of  your current branch one by one, until you’re all up to date. Awesome  huh?

Finally..

If you get stuck, run ‘git branch -a’ and it will show you exactly  what’s going on with your branches. You can see which are remotes and  which are local. This is a good headsup before you start to break  things! It’s worth remembering that git branches are basically just a  pointer, so to be able to work with those commits you need a local  branch which points to somewhere from which those commits are reachable

# Git Environtment Initial setting-up in Laptop

## SSH Key Generation steps

**To Create the ssh basic key pairs**

    cd ~
    cd .ssh 
    mkdir .ssh 
    cd .ssh 
    pwd 
    ssh-keygen -t rsa -C "<email id>"

**Check the access to**

    Github 
        ssh -T git@github.com 
    bitbucket  
        ssh -Tvvv git@bitbucket.org 

## Git Frequently Used Commands

**Configuring**
```shell
    #Git Config (Global/User-level) Syntax 
        git config --global setting value 

    #Configure User and Email 
        git config --global user.name "Revanth K Bayyana" 
        git config --global user.email "<email id>" 

    #Listing All Global Configuration Settings 
        git config --global --list 

    #For opening the config in editor and edit as per the tool choice 
        git config --global -e
    
    #Sample configuration is as below 
        [user]
            email = embedded.auto.revanth@gmail.com
            name = revanth.ubuntu
        [diff]
            tool = vscode
        [difftool "vscode"]
            cmd = code --wait --diff "$LOCAL" "$REMOTE"

    #Seeing Git's User-based Config file 
        cat ~/.gitconfig 
```


## Fresh Start

    pwd 
    cd <projects>/ 
    git init <git-proj-name> 

>Note: [git-proj-folder] is optional. If not supplied, Git will initialize the current directory.

## Other Important commands
**Commands for committing**

    git add README.md
    git commit -m "Initial commit"

>Note: Staging commands as below for more clarity

| Command    | Description                        |
|------------|:-----------------------------------|
| git add .  | adds new + modified, skips deleted |
| git add -u | adds modified + deleted, skips new |
| git add -A | adds all (new, modified, deleted)  |

    git push  (to main)

    git push origin <branch> (to the branch)

    git push -u origin <branch-name>  (to the new branch branch-name)
    

 **!! Important push**

    git push --force-with-lease
>Note: When you rebase or rewrite commit history intentionally.
    `--force-with-lease` is safer — it won’t overwrite others’ work.

**Unstage the files or directories**

    git restore --staged .
    git restore --staged build/compile_commands.json
**Git graphs**

    git log --oneline --graph --name-only

**Create alias for long commands as below**

    git config --global alias.loggraph "log --oneline --graph --color"
Then  we can use the below custom command

    git loggraph

**Git amending one of the commits**

1. Start the interactive Rebase until or one below commits (for the below done for one commit before)

    `git rebase -i HEAD~3`

    It opens a editor with 3 commit hashes with `pick`

        pick 18627eb 1st commit
        pick 121a66a 2nd commit
        pick dae18d0 3rd commit

    then we need to change the `pick` → `edit` for the commit which we wanted to modify then save and close the editor.

        pick 18627eb 1st commit
        edit 121a66a 2nd commit
        pick dae18d0 3rd commit

2. Do the necessary modification which we wanted to do for the files

    `git add -u (or)`
    `git add .`

3. Then proceed with amending the commit

    `git commit --amend`

    This opens your editor to amend the commit message.
4. Continue Rebase for applying the other commits

    `git rebase --continue`
    Then it opens the Apllying the remaining commits until it finishes the rebase.
5. Push the final changes..... Done!!


**Bring master’s new commit into your side branch:**
<br>MERGE (safe, common)
```shell
git checkout side-branch
git merge master
```
This creates a merge commit, combining:<br>
commits on side-branch<br>
new commit on master<br>
Pros:<br>
✔ keeps full history<br>
✔ safest option (no rewriting)   **-->This is what many companies prefer.**<br>

REBASE (clean history)

Replay the side-branch commits on top of master’s latest commit:
```shell
git checkout side-branch
git rebase master
```
This makes it look like:<br>
side-branch started after master’s new commit<br>
**Pros:**<br>
✔ clean linear history<br>
✔ no merge commit<br>
Cons:<br>
✖ rewrites history (don’t use on shared branches)

Merge - keeps history<br>
Rebase - keeps it cleaner



For Sublime Text `Copy Bookmarked Lines` process
- Select the string you wanted to search for then
- Alt+F3
- Ctrl+L
- Ctrl+Shift+L
- Copy
- Create new buffer
- Paste

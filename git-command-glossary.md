# Git Command Glossary

## push
**Definition:** Uploads local branch commits to a remote repository.

**Example:**
```
git push origin main
```
This pushes your local commits on the main branch to the remote named "origin".

## pull
**Definition:** Fetches changes from a remote repository and merges them into the current branch.

**Example:**
```
git pull origin develop
```
This fetches and merges changes from the develop branch of the remote "origin" into your current local branch.

## fetch
**Definition:** Downloads objects and refs from a remote repository without merging changes into your local branches.

**Example:**
```
git fetch --all
```
This fetches all branches from all remotes without merging.

## merge
**Definition:** Combines changes from different branches.

**Example:**
```
git merge feature-branch
```
This merges the feature-branch into your current branch.

## checkout
**Definition:** Switches branches or restores working tree files.

**Example:**
```
git checkout -b new-feature
```
This creates a new branch called "new-feature" and switches to it.

## commit
**Definition:** Records changes to the repository.

**Example:**
```
git commit -m "Add new login feature"
```
This commits your staged changes with the message "Add new login feature".

## add
**Definition:** Adds file contents to the index (staging area).

**Example:**
```
git add .
```
This stages all changes in the current directory for the next commit.

## status
**Definition:** Shows the working tree status.

**Example:**
```
git status
```
This displays the state of the working directory and the staging area.

## branch
**Definition:** Lists, creates, or deletes branches.

**Example:**
```
git branch -d old-feature
```
This deletes the branch named "old-feature".

## clone
**Definition:** Creates a copy of a remote repository.

**Example:**
```
git clone https://github.com/user/repo.git
```
This clones the repository at the given URL into a new directory in the current location.

## rebase
**Definition:** Reapplies commits on top of another base tip.

**Example:**
```
git rebase main
```
This moves the entire current branch to begin on the tip of the main branch.

## stash
**Definition:** Temporarily shelves changes so you can work on a different branch.

**Example:**
```
git stash push -m "Work in progress"
```
This saves your current changes with the message "Work in progress".

## log
**Definition:** Shows commit logs.

**Example:**
```
git log --oneline
```
This shows the commit history in a compact format, one commit per line.

## reset
**Definition:** Resets the current HEAD to the specified state.

**Example:**
```
git reset --hard HEAD~1
```
This moves the current branch backward by one commit, discarding changes.

## remote
**Definition:** Manages set of tracked repositories.

**Example:**
```
git remote add upstream https://github.com/original/repo.git
```
This adds a new remote named "upstream" pointing to the specified URL.

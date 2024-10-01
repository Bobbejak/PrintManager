# Daily Git Workflow

## Morning Routine: Sync with Remote

1. Ensure you're on the main branch:
   ```
   git checkout main
   ```

2. Fetch the latest changes from the remote:
   ```
   git fetch origin
   ```

3. Reset your local main to match the remote:
   ```
   git reset --hard origin/main
   ```

4. Clean up any untracked files (be careful, this will delete files):
   ```
   git clean -fd
   ```

## Start Your Work

5. Create a new branch for today's work:
   ```
   git checkout -b feature-YYYYMMDD
   ```
   (Replace YYYYMMDD with the current date)

## During the Day: Make Changes

6. Work on your files as normal

7. Stage your changes:
   ```
   git add .
   ```

8. Commit your changes:
   ```
   git commit -m "Brief description of changes"
   ```

9. Repeat steps 6-8 as needed throughout the day

## End of Day: Push Changes

10. Ensure all changes are committed (repeat steps 7-8 if necessary)

11. Switch back to the main branch:
    ```
    git checkout main
    ```

12. Pull the latest changes (in case someone else pushed while you were working):
    ```
    git pull origin main
    ```

13. Merge your work into main:
    ```
    git merge feature-YYYYMMDD
    ```

14. Push your changes to the remote:
    ```
    git push origin main
    ```

15. Delete your feature branch (optional):
    ```
    git branch -d feature-YYYYMMDD
    ```

## Handling Conflicts

If you encounter merge conflicts in step 13:

a. Open the conflicting files and resolve the conflicts manually

b. Stage the resolved files:
   ```
   git add .
   ```

c. Commit the merge:
   ```
   git commit -m "Merge feature-YYYYMMDD into main"
   ```

d. Continue from step 14

Remember: If at any point you're unsure about the state of your repository, you can use `git status` to check.

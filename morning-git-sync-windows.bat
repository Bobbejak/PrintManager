@echo off
:: Morning Git Sync Script for Windows
:: This script automates the morning routine for syncing with the remote Git repository

echo Checking out main branch...
git checkout main

echo Fetching latest changes from remote...
git fetch origin

echo Resetting local main to match remote...
git reset --hard origin/main

echo WARNING: The next step will delete untracked files.
echo Press Ctrl+C to cancel, or any other key to continue.
pause > nul

echo Cleaning up untracked files...
git clean -fd

echo Morning Git sync complete!

:: Keep the window open so the user can see the output
pause

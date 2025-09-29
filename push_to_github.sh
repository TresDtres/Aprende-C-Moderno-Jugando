#!/bin/bash

# Script to push C++ Space Colony course to GitHub
# Usage: ./push_to_github.sh [commit_message]

set -e  # Exit on any error

echo "🚀 C++ Space Colony - GitHub Upload Script"
echo "=========================================="

# Check if we're in a git repository
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    echo "❌ Error: Not a git repository. Please initialize git first:"
    echo "   git init"
    echo "   git remote add origin https://github.com/TresDtres/Aprende-C-Moderno-Jugando.git"
    exit 1
fi

# Check if remote origin is set
if ! git remote get-url origin > /dev/null 2>&1; then
    echo "❌ Error: No remote origin set. Please add your GitHub repository:"
    echo "   git remote add origin https://github.com/TresDtres/Aprende-C-Moderno-Jugando.git"
    echo ""
    echo "Replace YOUR_USERNAME and YOUR_REPO with your actual GitHub username and repository name."
    exit 1
fi

# Get commit message from argument or use default
COMMIT_MSG="${1:-'Update C++ Space Colony course - $(date +%Y-%m-%d\ %H:%M:%S)'}"

echo "📝 Commit message: $COMMIT_MSG"
echo ""

# Show git status
echo "📊 Current git status:"
git status --porcelain
echo ""

# Add all files
echo "➕ Adding files to git..."
git add .

# Check if there are changes to commit
if git diff --cached --quiet; then
    echo "ℹ️  No changes to commit. Repository is up to date."
    exit 0
fi

# Commit changes
echo "💾 Committing changes..."
git commit -m "$COMMIT_MSG"

# Push to GitHub
echo "⬆️  Pushing to GitHub..."
git push origin main 2>/dev/null || git push origin master 2>/dev/null || {
    echo "❌ Error: Could not push to main or master branch."
    echo "Please check your default branch name and try manually:"
    echo "   git branch -M main  # if you want to rename master to main"
    echo "   git push -u origin main"
    exit 1
}

echo ""
echo "✅ Success! Repository pushed to GitHub"
echo "🌐 Visit your repository at: $(git remote get-url origin | sed 's/\.git$//')"
echo ""
echo "🎉 C++ Space Colony course is now live on GitHub!"

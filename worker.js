// worker.js

self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }

        const users = await response.json();

        if (!users || users.length === 0) {
            throw new Error("No users returned from the API.");
        }

        self.postMessage({
            success: true,
            data: users
        });
    }
    catch (error) {
        self.postMessage({
            success: false,
            message: error.message
        });
    }
};

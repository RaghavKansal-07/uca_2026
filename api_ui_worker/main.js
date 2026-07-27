const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.postMessage("Fetch Users");

worker.onmessage = function (event) {

    if (event.data.success) {

        const users = event.data.users;

        users.forEach(user => {

            const p = document.createElement("p");

            p.textContent =
                `${user.name} - ${user.active ? "Active" : "Inactive"}`;

            usersDiv.appendChild(p);

        });

    }
    else {

        usersDiv.textContent = event.data.message;

    }

};

worker.onerror = function () {

    usersDiv.textContent = "Something went wrong.";

};
